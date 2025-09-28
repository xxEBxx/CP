#include<bits/stdc++.h>

using namespace std;
using ll = long long ;
typedef vector<int> vi;
#define f first
#define s second
const ll mod = 1e9 + 7;
void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll poww(ll a, ll b) {
    ll p = a;
    ll res = 1;
    while (b > 0) {
        if (b&((ll)1)) {
            res  = (res * p)% mod;
        }
        p = (p*p )% mod;
        b >>= 1;
    }

    return res;
}

int  main() {
    fast();
    int m,q;
    cin >> m >> q;
    vector<string> arr(m);
    for (int i=0;i<m;i++)
        cin >> arr[i];
    for (int i=0;i<q;i++) {
        ll num ;
        cin >> num;
        ll tot = 0;
        for (int j=0;j<m;j++) {
            ll lent = arr[j].length();
            if (lent > num)
                continue;
            ll a = 26;
            ll b = ((num - lent)%mod);
            ll ans = poww(a,b);
            ans = (ans * (num - lent + 1))%mod;
            tot = (tot + ans)%mod;
        }
        cout << tot << endl;
    }
}
