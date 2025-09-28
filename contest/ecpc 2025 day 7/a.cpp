#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast();
    ll t; cin >> t;
    while (t--) {
        ll a,b,l,r;
        cin >> a >> b >> l >> r;

        // all bits of B must already be in A
        if ((a & b) != b) {
            cout << "NO\n";
            continue;
        }

        string res = "YES";

        for (ll j = 0; j <= 30; j++) {
            if ( ((a >> j) & 1LL) && (((b >> j) & 1LL) == 0) ) {
                ll base   = (1LL << j);
                ll period = base * 2;
                ll len    = (r - l + 1);

                if (len > base) continue;     // always covers some 1s

                ll Lm = l % period;
                ll delta = (Lm < base ? base - Lm : 0LL);
                ll first_with_one = l + delta;

                if (first_with_one > r) {
                    res = "NO";
                    break;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
