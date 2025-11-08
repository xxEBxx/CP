
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll b=0;
        while ((1ll<<b) < n) {
            b++;
        }
        ll res=0;
        for (ll j=0;j<b;j++) {
            if ((n>>j)&1ll) continue;
            res += (1ll<<j);
        }
        cout<<res<<endl;
    }
    return 0;
}
