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

const ll maxn=(ll)1e5+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll n,m,dp[maxn][3],visited[maxn];
map<ll,vector<pair<ll,ll>>> g;

ll solve(ll from,ll used){
    if(from==n)
        return 0;
    if(dp[from][used]!=-1)
        return dp[from][used];
    visited[from]=1;
    ll res=1e18;
    for(auto elem : g[from]){
        if(visited[elem.f])continue;
        if (used == 0) {
            res = min(res,elem.s+solve(elem.f,0));
            res = min(res,elem.s/2 + solve(elem.f,1));
        }
        else if(used==1){
            res = min(res,elem.s/2 + solve(elem.f,2));
        }
        else if(used==2){
            res=min(res,elem.s + solve(elem.f,2));
        }
    }
    return dp[from][used]=res;
}

int main(){fast();cin>>n;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        ll a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    cout<<solve(1,0)<<endl;
    return 0;
}