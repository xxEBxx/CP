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
        ll n,q;
        cin >> n>>q;
        vi arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vi mins(n,0),maxs(n,1e9);
        for (ll i=0;i<q;i++) {
            ll index,l,r;cin>>index>>l>>r;
            mins[index-1] = max(mins[index-1],l);
            maxs[index-1] = min(maxs[index-1],r);
        }
        ll res=0;
        for (ll i=0;i<n;i++) {
            if (mins[i] > maxs[i]) {
                res=-1;
                break;
            }
            if (arr[i] > maxs[i])
                res += arr[i]-maxs[i];
            else if (arr[i] < mins[i])
                res += mins[i]-arr[i];

        }
        cout<<res<<endl;
    }
    return 0;
}

