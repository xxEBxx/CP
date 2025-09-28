
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int main() {
    fast();
    int n,m;
    cin>>n>>m;
    vvi g(n+1),n_g(n+1);
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        n_g[a].push_back(b);
        g[b].push_back(a);
    }


    int k;
    cin>>k;
    vi path(k+1);
    for (int i=1;i<=k;i++) {
        cin>>path[i];
    }

    int t = path[k];
    queue<ii> q;
    q.push({t,0});
    vi dist(n+1,-1);
    dist[t] = 0;

    while (!q.empty()) {
        auto head = q.front();
        q.pop();
        if (dist[head.f] != -1 && head.f!=t)
            continue;
        dist[head.f] = head.s;
        for (auto elem : g[head.f]) {
            if (dist[elem]!=-1)continue;
            q.push({elem,head.s+1});
        }
    }

    unordered_map<int,int> dist_reverse;
    for (int i=1;i<=n;i++) {
        dist_reverse[dist[i]]++;
    }

    int mn = 0, mx = 0;
    for (int i = 2; i <= k; i++) {
        int u = path[i-1], v = path[i];
        if (dist[u] != dist[v] + 1) {
            // edge not on any shortest path -> must rebuild
            mn++;
            mx++;
        } else {
            // edge is on a shortest path; check if multiple shortest-next choices exist from u
            int choices = 0;
            for (int w : n_g[u]) if (dist[w] == dist[u] - 1) choices++;
            if (choices > 1) mx++;
        }
    }
    cout << mn << " " << mx << "\n";


    return 0;
}
