#include <bits/stdc++.h>




using namespace std;


const int N = 5005, M = 2 * 1e3 + 3;


#define edges(u, v, c, e)  for(int e=head[u],v,c;~e  and (v=to[e],c=cap[e],1); e=nxt[e])
int head[N], nxt[M], to[M], cap[M], ne, n, src, snk, vis[N], vid;


void init() {
    ne = 0;
    memset(head, -1, n * sizeof head[0]);
}


void addEdge(int u, int v, int c) {
    to[ne] = v;
    cap[ne] = c;
    nxt[ne] = head[u];
    head[u] = ne++;
}


void addBiEdge(int u, int v, int c, int rc = 0) {
    addEdge(u, v, c);
    addEdge(v, u, rc);
}


int dfs(int u, int mn = INT_MAX) {
    if (u == snk or !mn) return mn;
    if (vis[u] == vid) return 0;
    vis[u] = vid;
    edges(u, v, c, e) {
        int f = dfs(v, min(mn, c));
        if (f) {
            cap[e] -= f;
            cap[e ^ 1] += f;
            return f;
        }
    }
    return 0;
}


long long maxFlow() {
    long long ret = 0;
    for (int f; ++vid, f = dfs(src); ret += f);
    return ret;
}


int main() {
    int n1,m;
    n = n1 + m + 10;
    scanf("%d%d", &n1, &m);
    vector<vector<int>> g(n+1);
    for (int i=1;i<=n;i++) {
        int k;cin >> k;
        for (int j=0;j<k;j++) {
            int a;cin >> a;
            g[i].push_back(i);
        }

    }

    int low = 1, high = n1 + 2;
    while (high - low > 0) {
        int c = (high + low)/2;
        init();
        addBiEdge(0,n1 + m + 5,c);
        for (int i=1;i<=n;i++){
            addBiEdge(n1 + m + 5, i, 1);
            for (auto c: g[i]) {
                addBiEdge(i, c+n1+1, 1);
            }
        }
        for (int i=1;i<=m;i++) {

        }
        src = 0;
        snk = n1 + m + 7;

        if (maxFlow()< m) {
            low = c + 1;
        }
        else {
            high = c;
        }

    }
    if (high > m)
    cout << -1 << endl;
    else cout << high << endl;
    return 0;
}
