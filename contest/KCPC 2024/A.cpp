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
        vi arr(n);
        vi bit(32);
        ll ways=1,x=0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            for (ll j=0;j<32;j++)
                bit[j] += arr[i]>>j &1;
        }

        for (ll i=0;i<32;i++) {
            ll poss = bit[i],oth = n-poss;
            if (poss==oth) {
                ways*=2;
            }
            else if (poss>oth) {
                x |= (1<<i);
            }
        }
        ll res=0;
        for (ll i=0;i<n;i++) {
            res += x^arr[i];
        }
        cout<<res<<" "<<ways<<endl;

    }
    return 0;
}
