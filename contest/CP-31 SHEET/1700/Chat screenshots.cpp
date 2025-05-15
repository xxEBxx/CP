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

const int maxn = (int)2e5 + 7;

vector<unordered_set<int>> g(maxn);
vi dfs_num(maxn, -1), dfs_low(maxn, 0), component(maxn, -1);
vector<bool> visited(maxn, false);
stack<int> S;
int dfsNumberCounter, current_component;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push(u);
    visited[u] = true;
    for (int v : g[u]) {
        if (dfs_num[v] == -1) {
            tarjanSCC(v);
        }
        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    if (dfs_low[u] == dfs_num[u]) {
        while (true) {
            int v = S.top(); S.pop();
            visited[v] = false;
            component[v] = current_component;
            if (v == u) break;
        }
        current_component++;
    }
}

void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        // Reset necessary data structures for each test case
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            dfs_num[i] = -1;
            dfs_low[i] = 0;
            component[i] = -1;
            visited[i] = false;
        }
        S = stack<int>();
        dfsNumberCounter = 0;
        current_component = 0;

        vvi mat(m + 1, vi(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> mat[i][j];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 2; j < n; ++j) {
                int u = mat[i][j];
                int v = mat[i][j + 1];
                g[u].insert(v);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dfs_num[i] == -1) {
                tarjanSCC(i);
            }
        }

        vector<unordered_set<int>> condensed(current_component);
        for (int i = 1; i <= n; ++i) {
            for (int v : g[i]) {
                if (component[i] != component[v]) {
                    condensed[component[i]].insert(component[v]);
                }
            }
        }

        if(condensed.size() == n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }
    return 0;
}