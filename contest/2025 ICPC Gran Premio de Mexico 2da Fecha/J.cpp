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

const ll maxn = (ll)  1e6 + 7;
const ll mod = (ll) 998244353;

ll f[maxn],invf[maxn];
ll inv(ll a) {
    return a <= 1 ? a : mod - (mod / a) * inv(mod % a) % mod;
}

void pre() {
    f[0]=1;
    for (ll i=1;i<maxn;i++) {
        f[i] = f[i-1]*i;
        f[i] %= mod;
    }
    invf[maxn-1] = inv(f[maxn-1]);
    for (ll i=maxn-2;i>=0;i--) {
        invf[i] = (i+1) * invf[i+1];
        invf[i] %= mod;
    }
}

ll c(ll k,ll n) {
    ll res = f[n];
    res *= invf[n-k];
    res %= mod;
    res *= invf[k];
    res %= mod;
    return res;
}

int main() {
    fast();
    pre();
    ll t;
    cin >> t;
    while (t--) {
        ll n,k;cin>>n>>k;
        ll res=0;
            res += c(k+1,n+1);
        cout<<res%mod<<endl;
    }
    return 0;
}
