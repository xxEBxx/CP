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

struct elem {
    ll val;
    multiset<ll> s;
};

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<elem> arr(32);
        for (ll i=0;i<n;i++) {
            ll a;
            cin>>a;
            if (a==1){
                ll val;
                cin >> val;
                arr[__builtin_popcount(val)].s.insert(val);
                arr[__builtin_popcount(val)].val += val;
            }
            else if (a==2) {
                ll val;
                cin>>val;
                if (!arr[val].s.empty()) {
                    arr[val].val -= *arr[val].s.begin();
                    arr[val].s.erase(arr[val].s.begin());
                }
            } else {
                ll l,r;
                cin>>l>>r;
                ll res=0;
                for (ll j=l;j<=r;j++) {
                    res+=arr[j].val;
                }
                cout<<res<<endl;
            }
        }
    }
    return 0;
}
