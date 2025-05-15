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

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,dp[1001][4],k;

int solve(int i,int fixed){
    if(i==n){
        if(fixed < n-k || fixed==n-1)return 0;
        return 1;
    }
    if(dp[i][fixed]!=-1)return dp[i][fixed];
    int res=solve(i+1,fixed+1)+solve(i+1,fixed);
    return dp[i][fixed]=res;
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    cout<<solve(0,0);
    return 0;
}