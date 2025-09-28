
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
using ull = unsigned long long;

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n,l,r,k;
        cin>>n>>l>>r>>k;
        if (n&1) {
            cout<<l<<endl;
        }
        else {
            if (n==2) {
                cout << -1 << endl;
                continue;
            }
            int  bits = 64 - __builtin_clzll(l);
            ull  p2   = (bits < 64 ? 1ULL << bits : 0ULL);
            if (l<= p2 && p2 <= r) {
                if (k <= n-2)cout<<l<<endl;
                else cout<< p2 <<endl;
            }
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}

