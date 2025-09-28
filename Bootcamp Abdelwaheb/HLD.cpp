
#include <bits/stdc++.h>


using namespace std;

const int N = 5e5 + 10;


vector<vector<int>> adj;
int n,par[N],dpth[N],sz[N],hvyChld[N],chHead[N],nti[N],itn[N],cnt;

void calcSz(int u){
    sz[u]=1;
    hvyChld[u]=-1;
    int mx=0, mxChld=-1;
    for (auto v: adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dpth[v] = dpth[u] + 1;
        calcSz(v);
        sz[u] += sz[v];
        if(sz[v] > mx) {
            mx = sz[v];
            mxChld = v;
        }
    }
    if(mx*2>= sz[u])
        hvyChld[u] = mxChld;
}

void hldDfs(int u,int h){
    chHead[u]=h;
    itn[nti[u]=cnt++]=u;
    if(~hvyChld[u])
        hldDfs(hvyChld[u], h);
    for (auto v: adj[u]) {
        if (v == par[u] || v == hvyChld[u]) continue;
        hldDfs(v, v);
    }

}
void hld(int root){
    dpth[root]=0;
    par[root]=-1;
    cnt=0;
    calcSz(root);
    hldDfs(root, root);

}

int lca(int u, int v) {
    while (chHead[u] != chHead[v]) {
        if (dpth[chHead[u]] < dpth[chHead[v]]) swap(u, v);
        u = par[chHead[u]];
    }
    return dpth[u] < dpth[v] ? u : v;
}

int main() {
    int q;
    scanf("%d%d", &n,&q);
    adj.resize(n);
    for(int u=1;u<n;++u){
        int v;
        scanf("%d", &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    hld(0);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v) );
    }
    return 0;
}
