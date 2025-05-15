#include<bits/stdc++.h>

using namespace std;
const int n=502;
const int inf =1000;
int dp[n][n];


int solve(int i,int j){
    if(i==j)return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
    int res=inf;
    for(int k=1;k<i;k++){
        res=min(res,solve(k,j)+solve(i-k,j));
    }
    for(int k=1;k<j;k++){
        res=min(res,solve(i,k)+solve(i,j-k));
    }
    dp[j][i]=1+res;
    return dp[i][j]=1+res;
}

int main(){
    int a,b;cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    dp[1][2]=1;dp[2][1]=1;
    
    cout<<solve(a,b);
}