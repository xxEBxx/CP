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
    ll n;
    cin>>n;
    ll mnx,mny,mxx,mxy;
    cin>>mnx>>mny;
    mxx=mnx;
    mxy=mny;
    for (ll i=1;i<n;i++) {
        ll a,b;
        cin>>a>>b;
        mnx = min(mnx,a);
        mxx = max(mxx,a);
        mny = min(mny,b);
        mxy = max(b,mxy);
    }

    cout << 2*(mxy-mny+2) + 2*(mxx-mnx+2)<<endl;

    return 0;
}
