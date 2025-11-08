#include <bits/stdc++.h>
using namespace std;

/* ---------- helpers ---------- */
vector<uint8_t> hexToBytes(string s) {
    vector<uint8_t> out;
    out.reserve(s.size() / 2);
    int hi = -1;
    for (char c : s) {
        if (isspace(c)) continue;
        int v = isdigit(c) ? c - '0'
                : (c >= 'a' && c <= 'f') ? 10 + c - 'a'
                : (c >= 'A' && c <= 'F') ? 10 + c - 'A'
                : -1;
        if (v < 0) throw runtime_error("Bad hex");
        if (hi == -1) hi = v;
        else { out.push_back((hi << 4) | v); hi = -1; }
    }
    if (hi != -1) throw runtime_error("Odd hex length");
    return out;
}


bool printable(uint8_t b){ return b>=0x20 && b<=0x7E; }
bool looksAscii(const vector<uint8_t>& v){
    int good=0;
    for(auto b:v) if(printable(b)) ++good;
    return double(good)/v.size() > 0.9;
}
string bytesToStr(const vector<uint8_t>& v){
    string s; s.reserve(v.size());
    for(auto b:v) s.push_back(char(b));
    return s;
}
vector<vector<uint8_t>> ct;

/*--------------------------------------------------------------
  Apply a crib to one chosen message, show result on all five
  --------------------------------------------------------------
  Parameters
    baseMsg : 0-based index of the ciphertext that *contains* the crib
    offset  : byte index inside that ciphertext where the crib begins
    crib    : ASCII plaintext you believe sits at that offset

  Example call
      // try the text "bob: Meet" starting at byte 0 of msg_3
      applyCrib(2, 0, "bob: Meet");
 ----------------------------------------------------------------*/
void applyCrib(int baseMsg, size_t offset, const string& crib){
    if (baseMsg < 0 || baseMsg >= (int)ct.size()) {
        cerr << "baseMsg out of range (0-4)\n";
        return;
    }
    const auto& base = ct[baseMsg];
    size_t L = crib.size();



    /* --- derive keystream bytes from the chosen message --- */
    vector<uint8_t> ks(L);
    for (size_t j = 0; j < L; ++j)
        ks[j] = base[offset + j] ^ uint8_t(crib[j]);

    cout << "=== Crib \"" << crib << "\" in msg_" << baseMsg + 1
         << " at offset " << offset << " ===\n";

    /* --- apply that keystream slice to ALL messages --- */
    for (size_t m = 0; m < ct.size(); ++m) {
        cout << "  msg_" << m + 1 << ": ";
        if (offset + L > ct[m].size()) {            // too short
            cout << "(---)\n";
            continue;
        }
        for (size_t j = 0; j < L; ++j)
            cout << char(ct[m][offset + j] ^ ks[j]);
        cout << '\n';
    }
    cout << string(40, '-') << '\n';
}


/* ---------- main ---------- */
int main(){
    ios::sync_with_stdio(false);

    vector<string> hex = {
        "c13a4d3d4bbed9f1393a7c7928da8a6ad3dc1e21d948fc34d6fe8e7d490d139bcfece93d01d1166811",
        "c132493740bed9f1233e32642bc8d868dbc10a76920fa8388fbd9e0e58014688c9dfe73b1c94046a02967a35",
        "c231426e05c99cc0253632706ddac36eda8f0e3adf5ff6609fecda0e1f1e0bc9ded3e52100924b2c",
        "c13a4d3d4bbed9e1302b3d752cdecf3ad0ce0e3dc34ab877d0e0de42491a038d8acffd2d1185572856d0226c84",
        "c132493740bed9f4243e2e6328dfc66392dd0826d948ec34def9da4f4f06038d869ceb211c864d3f55cb3a699c08"
    };
    for(auto& s:hex) ct.push_back(hexToBytes(s));
    size_t maxLen=0; for(auto& v:ct) maxLen=max(maxLen,v.size());
    applyCrib(4,0,"Alice: Quarterl");//This is the important function

    const vector<string> prefixes;//={"bob","alice","admin"};
    const vector<string> words={"bob: Wh","password","admin: ","login","secret","money",
    " password"," admin"," login"," secret"," money",
    " password "," admin "," login "," secret "," money ",
    "password ","admin ","login ","secret ","money ",
    " admin", ": password", ": login", ": secret"
};

    vector<string> dict=prefixes; dict.insert(dict.end(),words.begin(),words.end());

    vector<int> key(maxLen,-1);
    bool progress=false;
    while(progress){
        progress=false;

        for(size_t m=0;m<ct.size();++m){
            auto& C=ct[m];
            for(size_t i=0;i<C.size();++i){
                for(const string& w:dict){
                    size_t L=w.size();
                    if(i+L>C.size()) continue;

                    /* candidate key bytes */
                    vector<int> k(L);
                    bool clash=false;
                    for(size_t j=0;j<L;++j){
                        k[j]=C[i+j]^uint8_t(w[j]);
                        if(key[i+j]!=-1 && key[i+j]!=k[j]){clash=true;break;}
                    }
                    if(clash) continue;

                    /* test on all messages */
                    bool okay=true; vector<string> slices;
                    for(auto& C2:ct){
                        if(i+L>C2.size()){okay=false;break;}
                        vector<uint8_t> tmp(L);
                        for(size_t j=0;j<L;++j) tmp[j]=C2[i+j]^uint8_t(k[j]);
                        if(!looksAscii(tmp)){okay=false;break;}
                        slices.push_back(bytesToStr(tmp));
                    }
                    if(!okay) continue;

                    /* ---- diagnostic print ---- */
                    cout<<"[candidate offset "<<i<<"]\n";
                    for(size_t z=0;z<slices.size();++z)
                        cout<<"  msg_"<<z+1<<": "<<slices[z]<<"\n";
                    cout<<"----------------------------------------\n";

                    /* commit bytes to global key */
                    for(size_t j=0;j<L;++j)
                        if(key[i+j]==-1){ key[i+j]=k[j]; progress=true; }
                }
            }
        }
    }

    /* final output (optional)
    cout<<"\n*** Decryption with recovered key (unknown=?) ***\n";
    for(size_t idx=0;idx<ct.size();++idx){
        cout<<"msg_"<<idx+1<<": ";
        for(size_t i=0;i<ct[idx].size();++i){
            if(key[i]==-1) cout<<'?';
            else cout<<char(ct[idx][i]^key[i]);
        }
        cout<<"\n";
    }*/
    return 0;
}