#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=202;
const int mod=(int)1e9+7;

int n,m,k,arr[maxn][maxn],dp[maxn][maxn][2];

int solve(int i,int j,int odd){
    if(i==n-1 && j==m-1) {
        if(odd)return 3*arr[i][j];
        return arr[i][j];
    }
    if(dp[i][j][odd]!=-1)return dp[i][j][odd];
    if(i>n-1 || j>m-1) {
        dp[i][j][0] = -1e9;
        return dp[i][j][1] = -1e9;
    }
    int eat_now=arr[i][j];
    if(odd)eat_now*=3;
    return dp[i][j][odd]=eat_now+max(
            solve(i+1,j+k,1-odd),
            solve(i+k,j+1,1-odd)
            );
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];
    memset(dp,-1,sizeof(dp));
    int res=solve(0,0,1)-arr[0][0]*3;
    if(res<0)cout<<-1;
    else cout<<res;
    return 0;
}