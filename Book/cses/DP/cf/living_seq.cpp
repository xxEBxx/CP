//link : https://codeforces.com/contest/1811/problem/E
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    ll dp[13];
    //#of 4's for 10 to the i-th power
    dp[0]=0;
    for(int i=1;i<13;i++){
        dp[i]=pow(10,i-1)+9*dp[i-1];
        cout<<dp[i]<<" ";
    }

    while(t--){
        ll n;cin>>n;

    }

}