
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

ll dist(ll a,ll b,ll c,ll d) {
    return  (a-c)*(a-c) +(b-d)*(b-d);
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll xs,yx,xe,ye;
        cin>>xs>>yx>>xe>>ye;
        vi arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll mx = 0,ub=0;
        for (ll i = n-1; i >= 0 ; i--) {
            ub += arr[i];
            mx= max(mx,arr[i]);
        }

        ll d =  dist(xs,yx,xe,ye);
        ll lb = max(0ll, mx - (ub - mx));
        if ( lb*lb<=d && d <= ub*ub)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
