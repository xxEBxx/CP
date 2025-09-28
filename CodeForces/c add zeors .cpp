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
        int n;
        cin >> n;
        vi arr(n);
        map<int,vi> g;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            g[arr[i]+i-1].push_back(arr[i]+2*(i-1));
        }
        int res = n;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int head = q.front();
            res = max(res,head);
            q.pop();
            for (int c:g[head]) {
                q.push(c);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
