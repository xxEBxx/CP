// Correct and clean rewrite of the solution for "Maze of Time" (k ≤ 5)
// Uses Dijkstra with (node, mask) states and handles parallel edges safely.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll w;
    int id;              // 1-based corridor index
};

struct State {           // item for the priority queue
    int v;               // current room
    int mask;            // bitmask of used corridors in the k pairs
    ll dist;             // total time so far
    bool operator<(const State &o) const { return dist > o.dist; } // min-heap
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    // build the graph and remember each corridor's index
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; ll t;
        cin >> u >> v >> t;
        g[u].push_back({v, t, i + 1});
        g[v].push_back({u, t, i + 1});
    }

    // map: corridor id → special-pair id (0 = not special)
    vector<int> corr2pair(m + 1, 0);
    vector<ll> penalty(k + 1);
    for (int p = 1; p <= k; ++p) {
        int a, b; ll extra;
        cin >> a >> b >> extra;
        corr2pair[a] = corr2pair[b] = p;  // corridors a & b form pair p (1-based)
        penalty[p] = extra;
    }

    const ll INF = 4e18;
    const int MASKSZ = 1 << k;            // k ≤ 5 ⇒ at most 32 masks

    vector<vector<ll>> dist(n + 1, vector<ll>(MASKSZ, INF));
    priority_queue<State> pq;

    dist[1][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        if (cur.dist != dist[cur.v][cur.mask]) continue; // stale entry
        if (cur.v == n) break;                          // early exit optional

        for (const Edge &e : g[cur.v]) {
            int nextMask = cur.mask;
            ll nd = cur.dist + e.w;

            int p = corr2pair[e.id];        // is this corridor special?
            if (p) {
                int bit = p - 1;            // use bit positions 0 … k-1
                if (nextMask & (1 << bit))  // second corridor of the pair ⇒ add penalty
                    nd += penalty[p];
                nextMask ^= 1 << bit;       // toggle the bit (mark corridor used)
            }

            if (nd < dist[e.to][nextMask]) {
                dist[e.to][nextMask] = nd;
                pq.push({e.to, nextMask, nd});
            }
        }
    }

    ll ans = *min_element(dist[n].begin(), dist[n].end());
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}