#include<bits/stdc++.h>

using namespace std;
const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;
typedef long long ll;
int dp[maxn],ps[maxn];
int main(){
    int n,x;cin>>n>>x;
    memset(dp,0,sizeof(dp));
    memset(ps,0,sizeof(ps));
    //int added=0;
    int add=0;
    int k=1;
    while(k<x){
        dp[k]=1;
        k++;
    }
    dp[x]=2;
    for(int i=x+1;i<maxn;i++){
        dp[i]=(dp[i-1]%mod+dp[i-x]%mod)%mod;
    }
    for(int i=0;i<15;i++){
        //cout<<dp[i]<<" ";
    }
    for(int i=1;i<maxn;i++){
        ps[i]=(ps[i-1]%mod+dp[i]%mod)%mod;
    }
    cout<<endl;
    for(int i=0;i<15;i++){
        //cout<<ps[i]<<" ";
    }
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(a==0)cout<<ps[b]<<endl;
        int res=(ps[b]-ps[a-1])%mod;
        if(res<0)res+=mod;
        cout<<res<<endl;
    }
}
/*
 * 1859 48096
95515 99613
 * */