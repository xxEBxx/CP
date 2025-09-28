

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
const ll big = (ll)1e9+1;
int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ii> arr(n+1);
        vi ps(n+1,0),xs(n+1,0);
        for (ll i = 1; i <1+ n; i++) {
            cin >> arr[i].f >> arr[i].s;
            xs[i]=arr[i].f;
        }
        sort(all(arr));
        ps[n] = big - arr[n].f;
        for (ll i=n-1; i>=0 ;i--) {
            ps[i] = ps[i+1] + max(arr[i+1].f-arr[i].f , abs(arr[i+1].s-arr[i].s));
        }
        //ps[i] is price from a node to end, we only need now from xy to next poll
        ll q;cin>>q;
        for (ll i=0;i<q;i++) {
            ll x,y;
            cin>>x>>y;
            if (x >= xs[n]) {
                cout<<big-x<<endl;
                continue;
            }
            ll index = lower_bound(all(xs),x) - xs.begin();
            cout<< ps[index] + max(arr[index].f - x , abs(arr[index].s-y))<<endl;
        }
    }
    return 0;
}
