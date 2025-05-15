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

const int maxn=2001;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,k,dp[maxn][maxn];

int solve(int i,int number){
    if(i==k)return 1;
    if(dp[i][number]!=-1)return dp[i][number];

    int res=0;
    for(int next=number;next <= n ; next+=number){
        res+=solve(i+1,next);
        res%=mod;
    }
    return dp[i][number]=res;
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    int res=0;
    for(int i=1;i<=n;i++){
        res+=solve(1,i);
        res%=mod;
    }
    //cout<<dp[1][2];
    cout<<res<<endl;
    return 0;
}