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
const int maxn=102;

int dp[maxn][2];
int n,k,d;

int solve(int sum,int done_d){
    if(sum==0)return done_d;
    if(sum < 0)return 0;

    if(dp[sum][done_d]!=-1)return dp[sum][done_d];
    int res=0;
    for(int i=1;i<=k;i++){
        if(i<d)res+=solve(sum-i,done_d);
        else res+=solve(sum-i,1);
        res%=mod;
    }
    return dp[sum][done_d]=res;
}

int main(){fast();
    cin>>n>>k>>d;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,0)<<endl;
    return 0;
}