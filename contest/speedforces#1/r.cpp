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

const int maxn=51;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,dp[maxn][maxn][maxn][maxn];
vector<string> arr(maxn);

int solve(int i,int j,int x,int y){
    if(i==x && j==y) return arr[i][j]=='#';
    if(dp[i][j][x][y]!=-1)return dp[i][j][x][y];

    int res=max(x-i+1,y-j+1);
    for(int k=i;k<x;k++){
        res=min(res,
                solve(i,j,k,y)+
                solve(k+1,j,x,y));
    }

    for(int k=j;k<y;k++){
        res=min(res,
                solve(i,j,x,k)+
                solve(i,k+1,x,y));
    }

    return dp[i][j][x][y]=res;

}

int main(){fast();
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,n-1,n-1)<<endl;

}