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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;



int main(){fast();
    ifstream cin("cals.in");
    ll t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        vector<vector<ii>> g(n+1);
        for(ll i=0;i<m;i++){
            ll a,b,w;
            cin>>a>>b>>w;
            if(w > k)continue;
            g[a].emplace_back(b,w);
            g[b].emplace_back(a,w);
        }

        vvi dp(n+1,vi(k+1,0));

        dp[1][0]=1;

        for(ll dist = 0;dist<=k;dist++){
            for(ll i=1;i<=n;i++){
                for( auto neighb : g[i]){
                    if(dist + neighb.s > k)continue;
                    dp[neighb.f][dist + neighb.s] += dp[i][dist];
                    dp[neighb.f][dist + neighb.s] %= mod;
                }
            }
        }
        ll res=0;
        for(ll i=1;i<=n;i++){
            res += dp[i][k];
            res %= mod;
        }
        cout<<res<<endl;
    }
    return 0;
}