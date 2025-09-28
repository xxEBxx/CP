
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

vvi g;
vi depth,parent;
void dfs(int i) {

    for (int c : g[i]) {
        parent[c] = i;

    }

}

int main() {
    fast();
    int n,m;cin>>n>>m;
    vi arr(n+1,0),in(n+1,0);
    depth.resize(n+1,0);
    parent.resize(n+1,-1);
    for (int i=1;i<=n;i++)cin>>arr[i];

    g.resize(n+1);
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }

    return 0;
}
