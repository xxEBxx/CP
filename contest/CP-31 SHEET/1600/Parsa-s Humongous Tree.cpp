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

const ll maxn=(ll)1e5*2+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
map<ll,vi> g;
vector<pair<ll,ll>> nodes;
vector<vi> dp;
void dfs(ll p,ll curr){
    ll take_left=0,take_right=0;
    if(dp[curr][0]!=-1)
        return ;
    for(ll child:g[curr]){
        if(p==child)continue;
        dfs(curr,child);
        take_left += max(dp[child][1]+abs(nodes[child].s-nodes[curr].f),dp[child][0]+abs(nodes[child].f-nodes[curr].f));
        take_right += max(dp[child][1]+abs(nodes[child].s-nodes[curr].s),dp[child][0]+abs(nodes[child].f-nodes[curr].s));
    }
    dp[curr][0]=take_left;
    dp[curr][1]=take_right;

}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        g.clear();
        nodes.clear();
        nodes.push_back({0,0});
        ll n;cin>>n;
        dp.assign(n+2,{-1,-1});
        for(ll i=0;i<n;i++){
            ll a,b;cin>>a>>b;
            nodes.push_back({a,b});
        }
        for(ll i=0;i<n-1;i++){
            ll a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,1);
        ll res=0;
        for(ll i=1;i<=n;i++){
            res=max(dp[i][0],res);
            res=max(dp[i][1],res);
        }
        cout<<res<<endl;
    }
    return 0;
}