
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
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        vector<set<int>> g(n+1);
        for (int i = 0; i < m; i++) {
            int a,b;cin>>a>>b;
            g[a].insert(b);
            g[b].insert(a);
        }
        vvi n_g(n+1);
        for (int count = 1 ; count<=n ; count++){
            //assure each node is connected to 1 thne to 2 then 3 ...
            for (int i = 1; i <= n ; i++) {
                if (i==count)continue;
                if ( !g[i].empty() ) {
                    int other = *g[i].begin();
                    g[other].erase(i);
                    g[i].erase(other);

                    n_g[i].push_back(count);
                    n_g[count].push_back(i);
                }
                else break;
            }
        }

        bool val=true;

        for (int i=1;i<=n;i++) {
            while (!g[i].empty()) {
                int other = *g[i].begin();
                g[other].erase(i);
                g[i].erase(other);

                int mx = 1;
                if (!n_g[i].empty())
                    mx = n_g[i][n_g[i].size()-1] + 1;
                if (mx==i)mx++;
                n_g[i].push_back(mx);
                n_g[mx].push_back(i);
            }
        }


        queue<int> q;
        q.push(1);
        vi visited(n+1,0);
        visited[1]=1;
        while (!q.empty()) {
            int head = q.front();
            q.pop();
            for (auto neigh : n_g[head]) {
                if (visited[neigh])continue;
                q.push(neigh);
                visited[neigh]=1;
            }
        }
        for (int i=1;i<=n;i++) {
            if (visited[i]==0) {
                val=false;
                break;
            }
        }
        if (!val) {
            cout<<-1<<endl;
            continue;
        }

        int res=0;
        for (int i=1;i<=n;i++) {
            for (auto c:n_g[i]) {
                res += i+c;
            }
        }
        cout<<res/2<<endl;
    }
    return 0;
}
