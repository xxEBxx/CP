#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef vector<int> vi;
#define f first
#define s second
void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int  main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >>k;
        string s;
        cin >> s;
        ll l = 0;
        ll ans = 0;
        ll tot = 0;
        for (ll r = 0;r<n;r++) {
            if (s[r] == '0')
                tot++;
            if (s[r] == '1') {
                if (tot >= k)
                    tot = 0;
                else {
                    l = r - tot;
                    tot = 0;
                }
            }
            ans += (r - l + 1);
            //cout << r << " " << (r-l+1 ) << endl;
        }
        cout << ans << endl;
    }
}
