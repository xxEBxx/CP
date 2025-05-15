#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct State { int x, y, t; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> h(n, vector<ll>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> h[i][j];

    int x0, y0, xf, yf;
    cin >> x0 >> y0 >> xf >> yf;
    // to 0-based
    --x0; --y0; --xf; --yf;

    // dist[x][y][t]: min moves to reach (x,y) with last-trend t
    // t=0 start, t=1 uphill, t=2 downhill
    static int dist[500][500][3];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int t = 0; t < 3; t++)
                dist[i][j][t] = -1;

    deque<State> q;
    dist[x0][y0][0] = 0;
    q.push_back({x0, y0, 0});

    // 8 directions
    int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    while(!q.empty()){
        auto [x,y,t] = q.front();
        q.pop_front();
        int d = dist[x][y][t];
        for(int k = 0; k < 8; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            ll delta = h[nx][ny] - h[x][y];
            if(delta == 0) continue;

            int nt = -1;
            if(t == 0){
                // first move: either uphill or downhill
                nt = (delta > 0 ? 1 : 2);
            } else if(t == 1){
                // last was uphill, now must go downhill
                if(delta < 0) nt = 2;
            } else {
                // t == 2, last was downhill, now must go uphill
                if(delta > 0) nt = 1;
            }
            if(nt == -1) continue;
            if(dist[nx][ny][nt] == -1){
                dist[nx][ny][nt] = d + 1;
                q.push_back({nx, ny, nt});
            }
        }
    }

    int ans = -1;
    for(int t = 1; t <= 2; t++){
        if(dist[xf][yf][t] != -1){
            if(ans == -1 || dist[xf][yf][t] < ans)
                ans = dist[xf][yf][t];
        }
    }
    cout << ans << "\n";
    return 0;
}
