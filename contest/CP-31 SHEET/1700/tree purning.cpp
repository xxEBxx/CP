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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

unordered_map<int,vi> g;
vi depth,size_,leaf,deepest_child;
void dfs(int p,int v){
    int s=1;
    int l=1;
    depth[v] = 1+depth[p];
    deepest_child[v]=depth[v];
    for(int i: g[v]){
        if(i==p)continue;
        l=0;
        dfs(v,i);
        s += size_[i];
        deepest_child[v] = max(deepest_child[v],deepest_child[i]);
    }
    size_[v]=s;
    leaf[v]=l;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        g.clear();
        depth.assign(n+1,0);
        size_.assign(n+1,0);
        leaf.assign(n+1,0);
        deepest_child.assign(n+1,0);

        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(1,1);
        //stocking leafs at each layer
        vvi layered(n+1,vi()) ;
        vi count_reverse_deepest_child(n+1,0);

        for(int i=1;i<=n;i++){
            layered[depth[i]].push_back(i);
            count_reverse_deepest_child[deepest_child[i]]++;

        }

        int leafs_before=0;
        int res = n-1;
        for(int d=1;d<=n;d++){
            int local_remove=0;
            for(auto node : layered[d]){
                local_remove += size_[node]-1;
            }
            local_remove += leafs_before;
            leafs_before += count_reverse_deepest_child[d];
            res=min(res,local_remove);
        }
        cout<<res<<endl;

    }
    return 0;
}