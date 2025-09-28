#include <bits/stdc++.h>
#include <climits>
#define FAST ios::sync_with_stdio(false); cin.tie(0); 

using namespace std;

const int N = 2e5 + 10;


vector<vector<int>> adj;
int n,par[N],dpth[N],sz[N],hvyChld[N],chHead[N],nti[N],itn[N],cnt;

void calcSz(int u) {
    sz[u] = 1;
    hvyChld[u] = -1;
    int mx = 0;
    for (int v : adj[u]) if (v != par[u]) {
        par[v] = u;
        dpth[v] = dpth[u] + 1;
        calcSz(v);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            hvyChld[u] = v;
        }
    }
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

// segment tree
int seg[4*N + 10], val[N], input[N];
void build(int ni,int ns,int ne){
    if(ns==ne){ seg[ni]=val[ns]; return; }
    int mid=(ns+ne)>>1,l=ni<<1|1,r=l+1;
    build(l,ns,mid); build(r,mid+1,ne);
    seg[ni]=max(seg[l],seg[r]);
}

int query(int qs, int qe, int ni, int ns, int ne) {
    if(ns > qe || ne < qs) return INT_MIN;
    if(ns >= qs && ne <= qe) return seg[ni];
    int l = 2*ni + 1, r = l+1, m = ns + (ne - ns) / 2;
    return max(query(qs, qe, l, ns, m), query(qs, qe, r, m + 1, ne));
}

void update(int v, int idx, int ni, int ns, int ne) {
    if(idx > ne || idx < ns) return;
    if(ns == ne) {
        val[ns] = v;
        seg[ni] = val[ns];
        return;
    }
    int l = 2*ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    update(v, idx, l, ns, m); update(v, idx, r, m + 1, ne);
    seg[ni] = max(seg[l], seg[r]);
}


signed main() {
    FAST
    int q;
    scanf("%d%d",&n,&q);
    adj.resize(n);
    for(int i = 0; i < n; i++) scanf("%d",&input[i]);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d",&u,&v);

        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    hld(0);
    for (int i=0;i<n;i++) val[i]=input[itn[i]];
    build(0,0,n-1);

    vector<int> answers;
    while(q--) {
        int t, a, b;
        scanf("%d%d%d",&t,&a,&b);

        if(t == 1) {
            a--;
            update(b, nti[a], 0, 0, n - 1);
        }
        else {
            int ans = -1;
            a--; b--;
            while (chHead[a] != chHead[b]) {
                if (dpth[chHead[a]] < dpth[chHead[b]]) swap(a, b);
                ans = max(ans, query(nti[chHead[a]], nti[a], 0, 0, n - 1));
                a = par[chHead[a]];
            }
            ans = max( ans, dpth[a] < dpth[b] ? query(nti[a], nti[b], 0, 0, n - 1) : query(nti[b], nti[a], 0, 0, n - 1) );
            answers.push_back(ans);
        }
    }
    for(int& u : answers) printf("%d%c", u, " \n"[&u == &answers.back()]);
}