#include<bits/stdc++.h>

using namespace std;
const int maxn=101;
int dp[maxn][maxn];
vector<vector<int>> arr(101,vector<int> (101));

int solve(int i,int j,int pred) {
    if (i == 0 && j == 0) return dp[0][0] = arr[0][0];
    if (i == 0) return dp[0][j] = gcd(dp[0][j - 1], arr[0][j]);
    if (j == 0) return dp[i][0] = gcd(dp[i - 1][0], arr[i][j]);

    if (dp[i][j] != -1) return dp[i][j];
    int gec ;
    if(pred==-1)gec=arr[i][j];
    else gec = gcd(pred, arr[i][j]);
    int res = max(gcd(gec, solve(i - 1, j, arr[i][j])),
                  gcd(gec, solve(i , j-1, arr[i][j])));
    return dp[i][j] = res;
}

int main(){
    //cout<<gcd(8,);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
                cin>>arr[i][j];
            }
        }
        cout<<solve(n-1,m-1,-1)<<endl;
    }
}
/*
1
2 3
30 20 30
15 25 40
 */