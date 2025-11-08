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
        ll n,k;
        cin >> n>>k;
        vi a(n),bb(n);
        vector<ii> b(n);
        ll res=90;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            res+=a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> bb[i];
            b[i].f = bb[i]-a[i];
            b[i].s = i;
        }
        sort(all(b));
        reverse(all(b));
        vi taken(n,0);
        for (ll i=0;i<k;i++) {
            taken[b[i].s] = 1;
        }
        for (ll i=0;i<n;i++) {
            if (taken[i])
                cout<<bb[i]<<" ";
            else
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
