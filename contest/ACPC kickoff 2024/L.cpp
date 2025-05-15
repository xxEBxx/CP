#include <bits/stdc++.h>
using namespace std;

const int MAX_N    = 4 * 1000 + 2;     // up to 4002 chairs
const int MAX_TIME = 4 * 10000 + 1;    // up to 40001 minutes
const int INF      = 1'000'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    // presence[i][t] == 1 ⇔ person i attempts to cheat at minute t
    vector<vector<bool>> present(n, vector<bool>(MAX_TIME, false));

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        while (x--) {
            int t; cin >> t;
            present[i][t] = true;
        }
    }

    // Full DP table: dp[i][t] = max catches if at chair i at minute t
    vector<vector<int>> dp(n, vector<int>(MAX_TIME, -INF));

    dp[0][1] = (int)present[0][1];  // start at chair 0, minute 1
    int res = dp[0][1], min_time = 1;

    for (int t = 2; t < MAX_TIME; ++t) {
        for (int i = 0; i < n; ++i) {
            int best = dp[i][t - 1];             // stay
            if (i > 0)       best = max(best, dp[i - 1][t - 1]); // move left
            if (i + 1 < n)   best = max(best, dp[i + 1][t - 1]); // move right
            best += (int)present[i][t];               // catch attempt if any
            dp[i][t] = best;

            if (best > res) {
                res = best;
                min_time = t;
            } else if (best == res && t < min_time) {
                min_time = t;
            }
        }
    }

    cout << res << ' ' << min_time << '\n';
    return 0;
}
