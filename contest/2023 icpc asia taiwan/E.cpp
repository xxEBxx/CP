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

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll a,b,m,dp[65];

unordered_map<ll,ll> visited,value;

ll solve(ll x){
    if(x==0)
        return 2;
    if(visited[x]==1)
        return value[x];
    if(__builtin_popcount(x)==1){
        for(ll i=63;i>=0;i--) {
            if ((x >> i) & 1) {
                return dp[i];
            }
        }
    }
    ll res;
    for(ll i=0;i<=63;i++) {
        if ((x >> i) & 1) {
            ll k1=(1<<i),k2=x-(1<<i);
            res = dp[i]%m ;
            res *= solve(k2)%m ;
            res -= solve(abs(k1-k2)) % m;
            if(res<0)
                res+=m;
            res %= m;
        }
    }
    visited[x]=1;
    return value[x]=res;


}

int main(){fast();
    cin>>a>>b>>m;
    dp[0] = a%m;
    //cout<<dp[0];
    for(ll i=1;i<63;i++){
        dp[i] = dp[i-1]*dp[i-1] - 2;
        while(dp[i]<0)
            dp[i]+=m;
        dp[i] %= m;
        //visited[1<<i]=1;
        //value[1<<i]=dp[i];
        //cout<<dp[i]<<" ";
    }
    //cout<<endl;
    cout<<solve(b)<<endl;
    return 0;
}