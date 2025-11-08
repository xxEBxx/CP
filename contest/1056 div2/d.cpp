
#include <openssl/aes.h>

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using Bytes = std::vector<uint8_t>;

Bytes hex_to_bytes(const std::string& h) {
    if (h.size() & 1) throw std::runtime_error("odd hex length");
    Bytes v(h.size() / 2);
    for (size_t i = 0; i < v.size(); ++i) {
        unsigned int byte;
        std::sscanf(h.c_str() + 2 * i, "%2x", &byte);
        v[i] = static_cast<uint8_t>(byte);
    }
    return v;
}
std::string bytes_to_hex(const Bytes& v) {
    std::ostringstream oss;
    for (auto b : v) oss << std::hex << std::setw(2) << std::setfill('0')
                         << static_cast<int>(b);
    return oss.str();
}

void pkcs5_pad(Bytes& buf) {
    size_t pad = AES_BLOCK_SIZE - (buf.size() % AES_BLOCK_SIZE);
    buf.insert(buf.end(), pad, static_cast<uint8_t>(pad));
}
void pkcs5_unpad(Bytes& buf) {
    if (buf.empty() || buf.size() % AES_BLOCK_SIZE)
        throw std::runtime_error("bad padded length");
    uint8_t pad = buf.back();
    if (!pad || pad > AES_BLOCK_SIZE) throw std::runtime_error("bad pad value");
    for (size_t i = 0; i < pad; ++i)
        if (buf[buf.size() - 1 - i] != pad)
            throw std::runtime_error("bad pad bytes");
    buf.resize(buf.size() - pad);
}

inline void xor_block(uint8_t* out, const uint8_t* a, const uint8_t* b,
                      size_t n = AES_BLOCK_SIZE) {
    for (size_t i = 0; i < n; ++i) out[i] = a[i] ^ b[i];
}

Bytes cbc_encrypt(const Bytes& plain, const Bytes& key) {
    AES_KEY aes_enc;
    AES_set_encrypt_key(key.data(), 128, &aes_enc);

    Bytes iv(AES_BLOCK_SIZE);
    std::generate(iv.begin(), iv.end(), [] { return rand() & 0xff; });

    Bytes padded = plain;
    pkcs5_pad(padded);

    Bytes out = iv;
    Bytes prev = iv, block(AES_BLOCK_SIZE);

    for (size_t off = 0; off < padded.size(); off += AES_BLOCK_SIZE) {
        xor_block(block.data(), &padded[off], prev.data());
        AES_encrypt(block.data(), block.data(), &aes_enc);
        out.insert(out.end(), block.begin(), block.end());
        prev.assign(block.begin(), block.end());
    }
    return out;
}

Bytes cbc_decrypt(const Bytes& cipher, const Bytes& key) {
    if (cipher.size() < AES_BLOCK_SIZE || cipher.size() % AES_BLOCK_SIZE)
        throw std::runtime_error("bad ciphertext len");

    AES_KEY aes_dec;
    AES_set_decrypt_key(key.data(), 128, &aes_dec);

    Bytes iv(cipher.begin(), cipher.begin() + AES_BLOCK_SIZE);
    Bytes prev = iv, block(AES_BLOCK_SIZE), plain;

    for (size_t off = AES_BLOCK_SIZE; off < cipher.size();
         off += AES_BLOCK_SIZE) {
        AES_decrypt(&cipher[off], block.data(), &aes_dec);
        xor_block(block.data(), block.data(), prev.data());
        plain.insert(plain.end(), block.begin(), block.end());
        prev.assign(&cipher[off], &cipher[off] + AES_BLOCK_SIZE);
    }
    pkcs5_unpad(plain);
    return plain;
}

void inc_counter(Bytes& ctr) {           // big-endian 128-bit
    for (int i = ctr.size() - 1; i >= 0; --i)
        if (++ctr[i]) break;
}

Bytes ctr_crypt(const Bytes& in, const Bytes& key, bool encrypt) {
    AES_KEY aes_enc;
    AES_KEY aes_enc;
    AES_set_encrypt_key(key.data(), 128, &aes_enc);

    Bytes iv(AES_BLOCK_SIZE);
    Bytes data;
    if (encrypt) {
        /* fresh IV */
        std::generate(iv.begin(), iv.end(), [] { return rand() & 0xff; });
        data = in;
    } else {
        iv.assign(in.begin(), in.begin() + AES_BLOCK_SIZE);
        data.assign(in.begin() + AES_BLOCK_SIZE, in.end());
    }

    Bytes out;
    if (encrypt) out = iv;

    Bytes ctr = iv, keystream(AES_BLOCK_SIZE);
    size_t off = 0;
    while (off < data.size()) {
        AES_encrypt(ctr.data(), keystream.data(), &aes_enc);
        size_t chunk = std::min<size_t>(AES_BLOCK_SIZE, data.size() - off);
        for (size_t i = 0; i < chunk; ++i)
            out.push_back(data[off + i] ^ keystream[i]);
        inc_counter(ctr);
        off += chunk;
    }
    if (!encrypt) return out;
    return out;
}

/* ───── quick driver for the four given sets ─────────────── */
int main() {
    try {
        /* == CBC sets == */
        Bytes key_cbc = hex_to_bytes("140b41b22a29beb4061bda66b6747e14");

        Bytes ct1 = hex_to_bytes(
            "4ca00ff4c898d61e1edbf1800618fb2828a226d160dad07883d04e008a7897ee"
            "2e4b7465d5290d0c0e6c6822236e1daafb94ffe0c5da05d9476be028ad7c1d81");
        Bytes pt1 = cbc_decrypt(ct1, key_cbc);
        std::cout << "CBC-1: " << std::string(pt1.begin(), pt1.end()) << "\n\n";

        Bytes ct2 = hex_to_bytes(
            "5b68629feb8606f9a6667670b75b38a5b4832d0f26e1ab7da33249de7d4afc48"
            "e713ac646ace36e872ad5fb8a512428a6e21364b0c374df45503473c5242a253");
        Bytes pt2 = cbc_decrypt(ct2, key_cbc);
        std::cout << "CBC-2: " << std::string(pt2.begin(), pt2.end()) << "\n\n";

        /* == CTR sets == */
        Bytes key_ctr = hex_to_bytes("36f18357be4dbd77f050515c73fcf9f2");

        Bytes ct3 = hex_to_bytes(
            "69dda8455c7dd4254bf353b773304eec0ec7702330098ce7f7520d1cbbb20fc3"
            "88d1b0adb5054dbd7370849dbf0b88d393f252e764f1f5f7ad97ef79d59ce29f"
            "5f51eeca32eabedd9afa9329");
        Bytes pt3 = ctr_crypt(ct3, key_ctr, /*encrypt?*/ false);
        std::cout << "CTR-1: " << std::string(pt3.begin(), pt3.end()) << "\n\n";

        Bytes ct4 = hex_to_bytes(
            "770b80259ec33beb2561358a9f2dc617e46218c0a53cbeca695ae45faa8952aa"
            "0e311bde9d4e01726d3184c34451");
        Bytes pt4 = ctr_crypt(ct4, key_ctr, false);
        std::cout << "CTR-2: " << std::string(pt4.begin(), pt4.end()) << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
