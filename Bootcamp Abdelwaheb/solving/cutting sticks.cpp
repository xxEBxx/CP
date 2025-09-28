#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 51;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll pos_[MAXN];
ll dp [MAXN][MAXN];
int opt[MAXN][MAXN];
int n;                           // total sentinel points (cuts + 2)

ll solve() {
    for (int i = 1; i < n; ++i) {          // base segments of size 1
        dp [i][i+1] = 0;
        opt[i][i+1] = i + 1;
    }

    for (int len = 2; len < n; ++len) {    // segment length in points
        for (int s = 1; s + len <= n; ++s) {
            int e  = s + len;
            dp [s][e] = INF;

            int lo = opt[s][e-1];
            int hi = opt[s+1][e];
            for (int k = lo; k <= hi; ++k) {
                ll cand = dp[s][k] + dp[k][e] + pos_[e] - pos_[s];
                if (cand < dp[s][e]) {
                    dp [s][e] = cand;
                    opt[s][e] = k;
                }
            }
        }
    }
    return dp[1][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, m;
    while (cin >> L && L) {
        cin >> m;                           // number of real cuts

        memset(dp,  0x3F, sizeof(dp));
        memset(opt, 0,   sizeof(opt));

        pos_[1] = 0;
        for (int i = 2; i <= m + 1; ++i) cin >> pos_[i];
        pos_[m + 2] = L;
        n = m + 2;

        cout <<"The minimum cutting is " <<solve() << ".\n";
    }
    return 0;
}