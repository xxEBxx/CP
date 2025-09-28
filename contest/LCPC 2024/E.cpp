
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

map<ll,pair<vi,vi>> m;

struct triple {
    ll a,l,r;
};

ll fix(ll a) {
    a=a%mod;
    if (a<0)a+=mod;
    return a;
}

int main() {
    fast();

    ll n,q,k;
    cin>>n>>q>>k;
    vi pow(n+2,1);
    for (ll i=1;i<n+2;i++) {
        pow[i] = pow[i-1]*k;
        pow[i] %= mod;
    }
    vi ps(n+2,0);
    for (ll i=0;i<q;i++) {
        ll a,l,r;
        cin>>a>>l>>r;
        ps[l] += a;
        ps[r+1] -= a*pow[r-l+1];
        ps[l] = fix(ps[l]);
        ps[r+1] = fix(ps[r+1]);
    }

    ll curr = 0;
    for (ll i=1;i<=n;i++) {
        curr *= k;
        curr = fix(curr);
        curr += ps[i];
        curr = fix(curr);

        cout<<curr<<" ";
    }
    cout<<endl;


    return 0;
}
