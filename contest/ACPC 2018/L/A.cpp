#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;


vector<ll> parent(maxn,0);
vector<ll> depth(maxn,-1);
vector<vector<ll>> adj(maxn);
const ll logg=19;
vector<vector<ll>> up(maxn,vector<ll>(logg+2,-1));

void dfs(ll n){
    for(ll elem:adj[n]){//elemissonofn
        if(depth[elem]!=-1)continue;
        depth[elem]=depth[n]+1;
        parent[elem]=n;
        dfs(elem);
    }
}

ll find_kth(ll n,ll k){
    for(ll j=logg;j>=0;j--){
        if(k&(1<<j)){
            n=up[n][j];
        }
    }
    return n;
}

ll lca(ll a,ll b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }

    ll k = depth[a]-depth[b];
    a=find_kth(a,k);
    if(a==b)return a;


    for(ll j=logg;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];

        }
    }

    return parent[a];
}


int main(){
    ifstream cin("awesome.in");
    ll t;
    cin >> t;

    while(t--){
        parent.assign(maxn,0);
        depth.assign(maxn,-1);
        adj.assign(maxn,vector<ll>());
        up.assign(maxn,vector<ll>(logg,-1));

        ll n,l,r; cin >> n >> l >> r;


        for(ll i=0;i<n-1;i++){
            ll a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ll root=1;
        depth[root]=0;parent[root]=-1;
        dfs(root);


        for(ll i=1;i<=n;i++){
            up[i][0]=parent[i];
        }

        for(ll j=1;j<=logg;j++){
            for(ll i=1;i<=n;i++){
                if(up[i][j-1]==-1)continue;
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }


        ll res = 0;

        for(ll i=1;i<=n;i++){
            for(ll p=i+1;p<=n;p++){

                ll LCA = lca(i,p);
                ll dis = n - 1 - (abs(depth[LCA] - depth[i]) + abs(depth[LCA] - depth[p]));

                if( l <= dis && dis <= r)res++;

            }

        }
        cout << res << "\n";


    }
    return 0;
}