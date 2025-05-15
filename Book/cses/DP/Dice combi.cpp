#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define maxn 1e6+2
const ll mod= 1e9+7;
vector<ll> dp(maxn,-1);

ll solve(ll n){
    if(n<0)return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n]=(solve(n-1)+solve(n-2)+solve(n-3)
    +solve(n-4)+solve(n-5)+solve(n-6))%mod;
}

int main(){
    ll n;cin>>n;
    dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=4;
    cout<<solve(n)<<endl;
}