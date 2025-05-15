// https://cses.fi/problemset/task/2086/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int K = 3e3+1, N = 3e3+1;
ll pref[N];
ll C(int i, int j) {
    ll sm = pref[j]-pref[i-1];
    return sm*sm;
}
ll dp[K][N];
void compute(int k, int l, int r, int optl, int optr) {
    if (r < l) return;
    int mi = (l+r)/2;
    int opt = -1;
    dp[k][mi]=1e18;
    for (int i = optl; i <= min(mi, optr); i++) {
        if (dp[k][mi] > dp[k-1][i-1]+C(i, mi)) {
            dp[k][mi] = dp[k-1][i-1]+C(i, mi);
            opt = i;
        }
    }
    compute(k, l, mi-1, optl, opt);
    compute(k, mi+1, r, opt, optr);
}

int main() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> pref[i], pref[i]+=pref[i-1];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=1e18;

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        compute(i, 1, n, 1, n);
    }
    cout << dp[k][n] << '\n';
    return 0;
}
