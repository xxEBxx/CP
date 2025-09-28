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

ll solve(ll x,ll y) {
    return ((y+1ll)*y/2ll - x*(x-1ll)/2ll - 2ll *(y-x))/5ll;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll x,y;
        cin>>x>>y;
        if (y-x < 7) {
            ll res=0;
            for (ll i=x;i<y+1;i++) {
                res+=i/5;
            }
            cout<<res<<endl;
            continue;
        }
        ll res=0;
        while (x%5 != 0) {
            res += x/5ll;
            x++;
        }

        while (y%5 != 0) {
            res+=y/5;
            y--;
        }

        res += solve(x,y);
        cout<<res<<endl;
    }
    return 0;
}
