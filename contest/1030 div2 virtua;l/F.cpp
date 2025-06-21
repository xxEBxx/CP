

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
vi depth;
vvi g;
void dfs(int i,int p) {
    for (int c : g[i]) {
        if (c==p)continue;
        depth[c] = depth[i]+1;
        dfs(c,i);
    }
}

int main() {
    int p2[maxn];
    p2[0]=1;
    for (int i=1;i<maxn;i++) {
        p2[i] = 2*p2[i-1];
        p2[i] %= mod;
    }
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.resize(n+1,{});
        depth.resize(n+1,0);
        int tri=0;
        for (int i=0;i<n-1;i++) {
int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int res=0;
        for (int i=1;i<=n;i++) {
            res=max(depth[i],res);
        }
        cout<<



    }
    return 0;
}
