// aes_modes.cpp
/*
 * Minimal AES-CBC (with PKCS5 padding) and AES-CTR implementation
 * using Crypto++ for the raw AES block primitive.
 *
 * Build:
 *   g++ aes_modes.cpp -lcryptopp -std=c++17 -O2
 *
 * Example:
 *   ./aes_modes
 * should print the four recovered plaintext messages from the project
 * hand‑out as a self‑test.
 */

#include <cryptopp/aes.h>
#include <cryptopp/cryptlib.h>

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdint>
#include <iomanip>
#include <sstream>

using byte = uint8_t;

// ---------- Utility helpers ----------

// Convert hex string to byte vector
std::vector<byte> hex2bytes(const std::string& hex) {
    std::vector<byte> out;
    out.reserve(hex.size() / 2);
    for (size_t i = 0; i < hex.size(); i += 2) {
        unsigned int byteVal;
        std::stringstream ss;
        ss << std::hex << hex.substr(i, 2);
        ss >> byteVal;
        out.push_back(static_cast<byte>(byteVal));
    }
    return out;
}

// Convert byte vector to hex string
std::string bytes2hex(const std::vector<byte>& data) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (byte b : data) {
        oss << std::setw(2) << static_cast<int>(b);
    }
    return oss.str();
}

// PKCS5 padding for 16‑byte blocks
void pkcs5_pad(std::vector<byte>& data) {
    size_t padLen = CryptoPP::AES::BLOCKSIZE - (data.size() % CryptoPP::AES::BLOCKSIZE);
    data.insert(data.end(), padLen, static_cast<byte>(padLen));
}

void pkcs5_unpad(std::vector<byte>& data) {
    if (data.empty()) throw std::runtime_error("Invalid padding");
    byte padLen = data.back();
    if (padLen == 0 || padLen > CryptoPP::AES::BLOCKSIZE) throw std::runtime_error("Invalid padding");
    for (size_t i = 0; i < padLen; ++i) {
        if (data[data.size() - 1 - i] != padLen) throw std::runtime_error("Invalid padding");
    }
    data.resize(data.size() - padLen);
}

// XOR two byte arrays (in place on dst)
void xor_block(byte* dst, const byte* src, size_t len = CryptoPP::AES::BLOCKSIZE) {
    for (size_t i = 0; i < len; ++i) dst[i] ^= src[i];
}

// ---------- AES‑CBC ----------

std::vector<byte> aes_cbc_encrypt(const std::vector<byte>& key,
                                  const std::vector<byte>& iv,
                                  std::vector<byte> plaintext) {
    pkcs5_pad(plaintext);

    CryptoPP::AES::Encryption aesEnc(key.data(), key.size());

    std::vector<byte> ciphertext;
    ciphertext.reserve(iv.size() + plaintext.size());
    ciphertext.insert(ciphertext.end(), iv.begin(), iv.end()); // prepend IV

    std::array<byte, CryptoPP::AES::BLOCKSIZE> prev;
    std::copy(iv.begin(), iv.end(), prev.begin());

    for (size_t offset = 0; offset < plaintext.size(); offset += CryptoPP::AES::BLOCKSIZE) {
        byte* block = plaintext.data() + offset;
        xor_block(block, prev.data());
        std::array<byte, CryptoPP::AES::BLOCKSIZE> encBlock{};
        aesEnc.ProcessBlock(block, encBlock.data());
        ciphertext.insert(ciphertext.end(), encBlock.begin(), encBlock.end());
        prev = encBlock;
    }
    return ciphertext;
}

std::vector<byte> aes_cbc_decrypt(const std::vector<byte>& key, const std::vector<byte>& ciphertext) {
    if (ciphertext.size() < CryptoPP::AES::BLOCKSIZE) throw std::runtime_error("Ciphertext too short");
    std::vector<byte> iv(ciphertext.begin(), ciphertext.begin() + CryptoPP::AES::BLOCKSIZE);
    const byte* ctext = ciphertext.data() + CryptoPP::AES::BLOCKSIZE;
    size_t ctextLen = ciphertext.size() - CryptoPP::AES::BLOCKSIZE;
    if (ctextLen % CryptoPP::AES::BLOCKSIZE != 0) throw std::runtime_error("Ciphertext length not multiple of block size");

    CryptoPP::AES::Decryption aesDec(key.data(), key.size());

    std::vector<byte> plaintext(ctextLen);

    std::array<byte, CryptoPP::AES::BLOCKSIZE> prev;
    std::copy(iv.begin(), iv.end(), prev.begin());

    for (size_t offset = 0; offset < ctextLen; offset += CryptoPP::AES::BLOCKSIZE) {
        std::array<byte, CryptoPP::AES::BLOCKSIZE> decBlock;
        aesDec.ProcessBlock(ctext + offset, decBlock.data());
        xor_block(decBlock.data(), prev.data());
        std::copy(decBlock.begin(), decBlock.end(), plaintext.begin() + offset);
        std::copy(ctext + offset, ctext + offset + CryptoPP::AES::BLOCKSIZE, prev.begin());
    }

    pkcs5_unpad(plaintext);
    return plaintext;
}

// ---------- AES‑CTR ----------

void increment_counter(std::array<byte, CryptoPP::AES::BLOCKSIZE>& counter) {
    // Increment last bytes (big‑endian)
    for (int i = CryptoPP::AES::BLOCKSIZE - 1; i >= 0; --i) {
        if (++counter[i]) break;
    }
}

std::vector<byte> aes_ctr_process(const std::vector<byte>& key,
                                  const std::vector<byte>& iv,
                                  const std::vector<byte>& input) {
    CryptoPP::AES::Encryption aesEnc(key.data(), key.size());

    std::array<byte, CryptoPP::AES::BLOCKSIZE> counter{};
    std::copy(iv.begin(), iv.end(), counter.begin());

    std::vector<byte> output(input.size());

    size_t offset = 0;
    while (offset < input.size()) {
        std::array<byte, CryptoPP::AES::BLOCKSIZE> keystream{};
        aesEnc.ProcessBlock(counter.data(), keystream.data());
        size_t chunk = std::min<size_t>(CryptoPP::AES::BLOCKSIZE, input.size() - offset);
        for (size_t i = 0; i < chunk; ++i) {
            output[offset + i] = input[offset + i] ^ keystream[i];
        }
        increment_counter(counter);
        offset += chunk;
    }
    return output;
}

// ---------- Demo ----------

void self_test() {
    // CBC samples
    std::string cbcKeyHex = "140b41b22a29beb4061bda66b6747e14";
    std::string cbcC1Hex = "4ca00ff4c898d61e1edbf1800618fb2828a226d160dad07883d04e008a7897ee"
                           "2e4b7465d5290d0c0e6c6822236e1daafb94ffe0c5da05d9476be028ad7c1d81";
    std::string cbcC2Hex = "5b68629feb8606f9a6667670b75b38a5b4832d0f26e1ab7da33249de7d4afc48"
                           "e713ac646ace36e872ad5fb8a512428a6e21364b0c374df45503473c5242a253";

    auto cbcKey = hex2bytes(cbcKeyHex);
    auto cbcC1 = hex2bytes(cbcC1Hex);
    auto cbcC2 = hex2bytes(cbcC2Hex);

    std::cout << "Set 1: " << std::string(aes_cbc_decrypt(cbcKey, cbcC1).begin(),
                                           aes_cbc_decrypt(cbcKey, cbcC1).end()) << '\n';
    std::cout << "Set 2: " << std::string(aes_cbc_decrypt(cbcKey, cbcC2).begin(),
                                           aes_cbc_decrypt(cbcKey, cbcC2).end()) << '\n';

    // CTR samples
    std::string ctrKeyHex = "36f18357be4dbd77f050515c73fcf9f2";
    std::string ctrC1Hex = "69dda8455c7dd4254bf353b773304eec"
                           "0ec7702330098ce7f7520d1cbbb20fc3"
                           "88d1b0adb5054dbd7370849dbf0b88d3"
                           "93f252e764f1f5f7ad97ef79d59ce29f"
                           "5f51eeca32eabedd9afa9329";
    std::string ctrC2Hex = "770b80259ec33beb2561358a9f2dc617"
                           "e46218c0a53cbeca695ae45faa8952aa"
                           "0e311bde9d4e01726d3184c34451";

    auto ctrKey = hex2bytes(ctrKeyHex);
    auto ctrC1 = hex2bytes(ctrC1Hex);
    auto ctrC2 = hex2bytes(ctrC2Hex);

    // Extract IV (first 16 bytes) then data
    auto ctrIV1 = std::vector<byte>(ctrC1.begin(), ctrC1.begin() + CryptoPP::AES::BLOCKSIZE);
    auto ctrData1 = std::vector<byte>(ctrC1.begin() + CryptoPP::AES::BLOCKSIZE, ctrC1.end());

    auto ctrIV2 = std::vector<byte>(ctrC2.begin(), ctrC2.begin() + CryptoPP::AES::BLOCKSIZE);
    auto ctrData2 = std::vector<byte>(ctrC2.begin() + CryptoPP::AES::BLOCKSIZE, ctrC2.end());

    std::cout << "Set 3: " << std::string(aes_ctr_process(ctrKey, ctrIV1, ctrData1).begin(),
                                           aes_ctr_process(ctrKey, ctrIV1, ctrData1).end()) << '\n';
    std::cout << "Set 4: " << std::string(aes_ctr_process(ctrKey, ctrIV2, ctrData2).begin(),
                                           aes_ctr_process(ctrKey, ctrIV2, ctrData2).end()) << '\n';
}

int main() try {
    self_test();
    return 0;
} catch (const std::exception& ex) {
    std::cerr << "Error: " << ex.what() << '\n';
    return 1;
}
