#include<bits/stdc++.h>

using namespace std;
const int maxn=(int) 1e6+7;
const int mod=(int)1e9+7;
vector<vector<int>> dp(maxn,vector<int> (9,0));

int main(){
    for(int i=1;i<9;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<maxn;i++){
        for(int j=1;j<9;j++){
            if(j==2 ||j==8 || j==7){
                dp[i][j]=dp[i-1][3];
                dp[i][j]=(dp[i][j]+dp[i-1][7])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][8])%mod;

                dp[i][j]%=mod;
            }
            else{
                dp[i][j]=dp[i-1][1];
                dp[i][j]=(dp[i][j]+dp[i-1][2])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][4])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][5])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][6])%mod;
            }

        }
    }
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<(dp[n][3]+dp[n][7])%mod<<endl;
    }
}