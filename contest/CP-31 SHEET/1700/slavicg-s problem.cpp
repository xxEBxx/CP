#include<bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> compute_xor(int start, vector<vector<pair<int, int>>> &adj) {
    vector<int> xor_dist(n+1, 0);
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    xor_dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if(u==b)continue;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int p = edge.second;
            if (!visited[v]) {
                visited[v] = true;
                xor_dist[v] = xor_dist[u] ^ p;
                q.push(v);
            }
        }
    }
    return xor_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        vector<vector<pair<int, int>>> adj(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].emplace_back(v, p);
            adj[v].emplace_back(u, p);
        }
        vector<int> xor_a = compute_xor(a, adj);
        vector<int> xor_b = compute_xor(b, adj);



        bool ans = false;
        if (xor_a[b] == 0) {
            ans = true;
        } else {
            xor_a[b]=-1;
            xor_b[a]=-3;
            xor_a[a]=-10;
            xor_b[b]=-30;
            unordered_map<int,int> s;
            for (int i = 1; i <= n; ++i) {
                s[xor_a[i]]=1;
            }
            for (int i = 1; i <= n; ++i) {
                if (s[xor_b[i]]==1){
                    ans=true;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}