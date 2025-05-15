#include<bits/stdc++.h>

using namespace std;
const int maxn=(int) 3 * 1e5 +8;
const int mod=(int) 1e9 +7;
typedef long long ll;
vector<ll> dp(maxn,0);

int main(){
    dp[0]=1;dp[1]=1;
    for(int i=2;i<maxn;i++){
        dp[i]=(dp[i-1] + ((2* ((i-1)*dp[i-2] % mod)) %mod) ) %mod;
    }
    //for(int i=0;i<10;i++)cout<<dp[i]<<" ";
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        for(int i=0;i<m;i++){
            ll a,b;cin>>a>>b;
            if(a==b)n--;
            else n-=2;
        }
        cout<<dp[n]<<endl;

    }
}