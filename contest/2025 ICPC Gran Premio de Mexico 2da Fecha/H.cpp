#include <bits/stdc++.h>
using namespace std;

struct Ledge {
    long long x, y;   // coordinates
    int rod;          // 1 = has metal rod
};

inline long long sq(long long v) { return v * v; }
inline bool within(long long dx,long long dy,long long R){
    return sq(dx)+sq(dy) <= sq(R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long H, K;
    if(!(cin >> N >> H >> K)) return 0;
    vector<Ledge> ledge(N);
    for (auto &p: ledge) cin >> p.x >> p.y >> p.rod;

    long long sx, sy; cin >> sx >> sy;
    int start = -1;
    for (int i = 0; i < N; ++i)
        if (ledge[i].x == sx && ledge[i].y == sy) { start = i; break; }

    if (start == -1) { cout << -1; return 0; }        // should not occur
    if (ledge[start].y == 0) { cout << 0; return 0; } // already at surface

    const int SURF = N;                               // extra node id
    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[start] = 0;  q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        const auto& P = ledge[v];

        /* push straight to surface? */
        if (P.rod && -P.y <= H) {
            cout << dist[v] + 1;
            return 0;
        }

        /* scan every other ledge */
        for (int u = 0; u < N; ++u) if (u != v && dist[u] == -1) {
            const auto& Q = ledge[u];
            long long dx = Q.x - P.x, dy = Q.y - P.y;

            bool canPush = (P.rod && within(dx,dy,H));
            bool canPull = (Q.rod && within(dx,dy,K));

            if (canPush || canPull) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    cout << -1;                                       // unreachable
    return 0;
}
