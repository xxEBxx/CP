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

const int maxn=(int)1e3+2;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,m,dp[maxn][maxn][11];

int solve(int a,int b,int index){
    if(index==m){
        return 1;
    }
    if(dp[a][b][index]!=-1)
        return dp[a][b][index];

    int res=0;
    for(int i=a;i<=n;i++){
        for(int j=i;j<=b;j++){
            res+=solve(i,j,index+1);
            res%=mod;
        }
    }
    return dp[a][b][index]=res;
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            res += solve(i,j,1);
            res %= mod;
        }
    }
    cout<<res<<endl;
    return 0;
}