
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
vi r,arr;
int dp[maxn],vis[maxn],cnt,n;
int solve(int i) {
    if (i==n)
        return 0;
    if (vis[i] == cnt)
        return dp[i];

    int res = solve(i+1);
    if (r[i] != -1) {
        res=max(res,arr[i]+solve(r[i]+1));
    }
    vis[i]=cnt;
    return dp[i] = res;
}

int main() {
    fast();
    int t;
    cin >> t;
    cnt=0;
    memset(vis,0,sizeof(vis));
    while (t--) {
        cnt++;
        cin >> n;
        arr.assign(n,0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        unordered_map<int,set<int>> count;
        r.assign(n,-1);
        for (int i=0;i<n;i++) {
            count[arr[i]].insert(i);
            if (count[arr[i]].size()==arr[i]) {
                r[*count[arr[i]].begin()] = i;
                count[arr[i]].erase(count[arr[i]].begin());
            }
        }

        cout<<solve(0)<<endl;

    }
    return 0;
}
