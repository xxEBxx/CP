#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;

const int MAXN = 4005;
const int MAXK = 805;

ll arr[MAXN][MAXN];
ll dp[MAXK][MAXN],c[MAXN][MAXN],n;

void cost() {
    for (int l=1;l<=n;l++) {
        for (int r=1;r<=n;r++) {
            c[r][l] = (arr[r][r] - arr[l - 1][r] - arr[r][l - 1] + arr[l - 1][l - 1]) / 2;
            c[l][r] = c[r][l];
        }
    }
}

void solve(int k, int s, int e, int optL, int optR) {
    if (s > e) return;
    int mid = (s + e) >> 1;
    ll best = 1e18;
    int opt = optL;

    for (int j = optL; j <= min(mid, optR); ++j) {
        ll cur = dp[k - 1][j - 1] + c[j][mid];
        if (cur < best) {
            best = cur;
            opt = j;
        }
    }
    dp[k][mid] = best;
    solve(k, s, mid - 1, optL, opt);
    solve(k, mid + 1, e, opt, optR);
}

void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast();

    int n, k;
    cin >> n >> k;

    // Read matrix and build 2D prefix sum
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >>arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    cost();
    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = 0;

    // Run divide & conquer DP
    for (int i = 1; i <= k; ++i)
        solve(i, 1, n, 1, n);

    cout << dp[k][n] << '\n';
    return 0;
}
