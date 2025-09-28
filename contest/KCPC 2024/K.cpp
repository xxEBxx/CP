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


void dfs(int a,vector<int> & temp1,vector<int> &temp2,vector<vector<int>> &g,vector<int> &vis,vector<int> &val) {
    vis[a] = 1;
    temp1.push_back(a);
    temp2.push_back(val[a]);
    for (auto x:g[a]) {
        if (vis[x])continue;
        dfs(x,temp1,temp2,g,vis,val);
    }
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n,m;cin >> n >> m;
        vector<int> val(n+1);
        vector<vector<int>> g(n+1);
        vector<int> visited(n+1,0);
        for (int i = 1 ;i<=n;i++) {
            cin >> val[i];
        }
        for (int i = 0 ;i<m;i++) {
            int a,b;cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int res = 1;
        for (int i=1;i<=n;i++) {
            if (visited[i] == 1)continue;
            vector<int> temp1;
            vector<int> temp2;
            dfs(i,temp1,temp2,g,visited,val);
            sort(all(temp1));
            sort(all(temp2));
            for (int j=0;j<temp2.size();j++) {
                if (temp1[j] != temp2[j])res = 0;
            }
        }

        if (res)cout << "YES"<<endl;
        else cout << "NO"<<endl;


    }
    return 0;
}
