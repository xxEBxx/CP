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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=53;
int dp[maxn][maxn],n,k,m;

ll solve(ll n,ll k){
    if(n<=0)return 0;
    if(k==1)return k<=m;
    if(dp[n][k]!=-1)return dp[n][k];
    int res=0;
    for(int i=1;i<=m;i++){
        //we iterate over the size of the last block
        res+=solve(n-i,k-1);
    }
    return dp[n][k]=res;
}

int main(){fast();
    while(cin>>n>>k>>m){
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)dp[i][j]=-1;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}