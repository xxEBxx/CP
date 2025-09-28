#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; if (!(cin >> n)) return 0;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll N = 1 << n, FULL = N - 1;

    vector<ll> xr(N, 0);
    for (ll m = 1; m < N; ++m) {
        ll b = m & -m;                  // lowbit
        ll i = __builtin_ctz(b);
        xr[m] = xr[m ^ b] ^ a[i];
    }

    const ll NEG = -1e9;
    vector<ll> best(N, NEG), kmin(N, 1e9);
    best[0] = 0; kmin[0] = 0;

    for (ll mask = 0; mask < N; ++mask) {
        ll rem = FULL ^ mask;
        if (rem == 0) continue;
        for (ll sub = rem; sub; sub = (sub - 1) & rem) {
            ll nxt = mask | sub;
            ll candSum = best[mask] + xr[sub];
            ll candK   = kmin[mask] + 1;
            if (candSum > best[nxt] || (candSum == best[nxt] && candK < kmin[nxt])) {
                best[nxt] = candSum;
                kmin[nxt] = candK;
            }
        }
    }

    cout << best[FULL] << ' ' << kmin[FULL] << "\n";
    return 0;
}
