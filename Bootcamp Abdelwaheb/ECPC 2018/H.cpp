
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

struct node{
    int i,dist;
};

int main() {
    fast();
    ifstream cin("path.in");
    int t;
    cin >> t;
    while (t--) {
        int n,m,u,l,k;
        cin>>n>>m>>u>>l>>k;
        vector<vector<vi>> g(n+1);
        for (int i=0;i<m;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back({b,c,i});
            g[b].push_back({a,c,i});
        }

        //we will have a node , max edge , distance so far

        queue<node> q;
        q.push({u,0});
        vi visited(m+1,0);
        int res=0;
        while (!q.empty()) {

            node head = q.front();
            q.pop();
            if (head.dist == k)break;
            for (auto c:g[head.i]) {
                if (visited[c[2]]==1)continue;
                visited[c[2]]=1;
                res = max(res,c[1]);
                q.push({c[0],head.dist+1});
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
