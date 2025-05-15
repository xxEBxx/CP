#include<bits/stdc++.h>

using namespace std;
const int mod=1e9+7;

int main(){
    int n,k;cin>>n>>k;
    vector<int> piece;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        piece.push_back(v);
    }
    int dp[k+1];
    memset(dp,0, sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k+1;j++){
            if(j-piece[i]>=0)
                dp[j] = (dp[j] + dp[j-piece[i]]) % mod;

        }
    }
    cout<<dp[k];
}