#include<bits/stdc++.h>

using namespace std;
int maxn=5002;
string a,b;
vector<vector<int>> dp(maxn,vector <int> (maxn,-1));
bool cost(int i,int j){
    return a[i]!=b[j];
}

int main(){
    getline(cin,a);
    getline(cin,b);
    //cout<<a ;
    int n=(int)a.size(),m=(int)b.size();
    //cout<<solve(n-1,m-1);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j < 1+m;j++){
            dp[i][j]=min(min(
                    dp[i-1][j]+1,
                    dp[i][j-1]+1),
                         dp[i-1][j-1]+cost(i-1,j-1));
        }
    }
    cout<<dp[n][m];
}