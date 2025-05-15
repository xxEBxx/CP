#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1002;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll n,k;
ll dp[maxn][maxn];

ll solve(ll i,ll j){
    if(j==0)return 0;
    if(i==0)return 1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll res = solve(i-1,j);
    res+=solve(n-i,j-1);
    res%=mod;
    return dp[i][j]=res;

}

int main(){fast();
    ll t;cin>>t;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<maxn;i++){
        dp[0][i]=1;
        dp[i][0]=0;
    }

    while(t--){
        cin>>n>>k;
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                dp[i][j] = (dp[i-1][j] + dp[n-i][j-1])%mod;
            }
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}
