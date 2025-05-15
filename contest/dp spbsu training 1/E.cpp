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

const int maxn=501;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int arr[maxn][maxn],n,m,dp[maxn][maxn][3];

int solve(int i,int j,int from){
    if(j<0 || j>m-1 || i>n-1)return 1e9;
    if(i==n-1 && j==m-1)return arr[i][j];
    if(dp[i][j][from]!=-1)return dp[i][j][from];
    int res=1e9;
//we want to minimize the max_depth aka go from depth with minimal
    if(from==0){
        res=min(res,solve(i+1,j,0));
        res=min(res,solve(i,j+1,1));
        res=min(res,solve(i,j-1,2));
    }
    else if(from ==1){
        res=min(res,solve(i+1,j,0));
        res=min(res,solve(i,j+1,1));
    }
    else {
        res=min(res,solve(i+1,j,0));
        res=min(res,solve(i,j-1,2));
    }
    return dp[i][j][from]=max(arr[i][j],res);
}


int main(){fast();
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0)<<endl;
    return 0;
}