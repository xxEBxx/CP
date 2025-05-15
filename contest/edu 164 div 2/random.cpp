#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=2 * 1e5+2;
vector<ll> facto(maxn+1);

int main(){
    facto[0]=1;
    for(int i=1;i<maxn+1;i++){
        facto[i]=(i*facto[i-1])%mod;
    }
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll len=0,to_add=0,res=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                to_add++;
            }
            else if(to_add!=0){
                len+=to_add;
                res=(res*(to_add+1))%mod;
                to_add=0;
            }
        }
        len+=to_add;
        res=(res*(to_add+1))%mod;
        res=(res * facto[len])%mod;
        cout<<len<<" "<<res<<endl;
    }
}