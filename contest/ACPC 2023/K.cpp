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
vvi g;
vi sz,sp,is_special,parent,sum,to_be_deleted,process;
void dfs(int v,int p){
/*
    if(g[v].size()==1){
        if(is_special[v]==1)
            sum[1]++;
        return ;
    }
    if(is_special[v]==1)
        sp[v]++;
    for(int elem : g[v]){
        if(elem==p)continue;
        dfs(elem,v);
        sp[v]+=sp[elem];
        sz[v]+=sz[elem];

    }
    sum[sz[v]] += sp[v];
*/

    for(int elem : g[v]){
        if(elem==p)continue;
        parent[elem]=v;
        dfs(elem,v);
        sz[v]+=sz[elem];
        sp[v]+=sp[elem];
    }
    sp[v]+=is_special[v];
    sum[sz[v]]+=sp[v];

    if(process[p] != 1 && g[p].size() == 2 || g[p].size() == 1){
        to_be_deleted[sz[v]] += sp[v];
        process[p] = 1;
    }
}

int main(){fast();
    int n,m;cin>>n>>m;
    g.resize(n+1);
    sz.resize(n+1,1);
    sp.resize(n+1,0);
    is_special.resize(n+1,0);
    parent.resize(n+1,0);
    sum.resize(n+1,0);
    to_be_deleted.resize(n+1,0);
    process.resize(n+1,0);



    parent[1]=1;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        int val;cin>>val;
        is_special[val]=1;
    }
    parent[1] = 1;
    dfs(1,1);
    //for(int i=1;i<=n;i++)cout<<sz[i]<<" ";
    vector<int> curr,next;
    curr.push_back(1);
    vi ans;
    ans.push_back(n);

    //for(int i=1;i<=n;i++)cout<<sum[i]<<" ";

    for(int i=1;i<n;i++){
        if(sum[i] + sum[i+1] - to_be_deleted[i] == m){
            ans.push_back(i);
        }
    }

    cout << endl;

    sort(all(ans));
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}