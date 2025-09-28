#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)x

typedef long long ll;
typedef vector<ll> vi;

int main(){
    //string s = "PHHW PH DIWHU WKH WRJD SDUWB";
    string s = "OVDTHUFWVZZPISLRLFZHYLAOLYL";

    for (int i=0;i<26;i++) {
        string ss=s;
        for (int j=0;j<s.size();j++) {
            if (ss[j] == ' ')continue;
            if (ss[j]+i > 'Z')ss[j] = ss[j]+i-26;
            else ss[j]+=i;
        }
        cout<<ss<<" "<<i<<endl;
    }


}