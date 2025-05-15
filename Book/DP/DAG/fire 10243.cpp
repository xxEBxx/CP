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

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

map<ii,vector<ii>> dag;
map<int ,vi> g;
int n;
int dp[1005][2];

int solve(int i, int state) {
    if (dag[{i, state}].empty()) return state;
    if (dp[i][state] != -1) return dp[i][state];
    int res;
    map<int,int> local_visit;
    if (state == 0) {
        res=0;
        for (auto elem : dag[{i, 0}]) {
            res += solve(elem.f, 1);
        }
    } else if (state == 1) {
        res=1;
        for (auto elem : dag[{i, 1}]) {
            if(local_visit[elem.f]>0)continue;
            local_visit[elem.f]+=1;
            if(solve(elem.f,1)>solve(elem.f,0))res += solve(elem.f, 0);
            else res+=solve(elem.f,1);
        }
    }
    return dp[i][state] = res;
}

int visited[1005];
void make_dag(int i) {
    visited[i] = 1;
    for (int child : g[i]) {
        if (visited[child] == 0) {
            dag[{i, 1}].push_back({child, 1});
            dag[{i, 1}].push_back({child, 0});
            dag[{i, 0}].push_back({child, 1});
            make_dag(child);
        }
    }
}

int main() {
    fast();
    while (cin >> n) {
        if (n == 0) break;
        if(n==1){
            int k;cin>>k;
            cout<<1<<endl;
            continue;
        }
        g.clear();
        dag.clear();
        memset(dp, -1, sizeof(dp));
        memset(visited, 0, sizeof(visited));
        for (int kk = 0; kk < n; kk++) {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                int to;
                cin >> to;
                g[kk + 1].push_back(to);
                g[to].push_back(kk + 1);
            }
        }
        make_dag(1);

        cout << min(solve(1, 0), solve(1, 1)) << endl;
    }
    return 0;
}
