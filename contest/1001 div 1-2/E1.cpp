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

vi banned,arr;
int n,node_max;
map<int,vi> g;

void dfs_ban(int p,int v,int in_subtree){
    if(in_subtree==1)
        banned.push_back(v);
    for(auto child:g[v]){
        if(child==p)continue;
        if(v == node_max)
            dfs_ban(v,child,1);
        else
            dfs_ban(v,child,in_subtree);
    }

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        banned.clear();
        arr.assign(n+1,0);
        g.clear();
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        node_max = max(all(arr))-arr.begin();
        banned.push_back(node_max);
        dfs_ban(1,1,0);


    }
    return 0;
}