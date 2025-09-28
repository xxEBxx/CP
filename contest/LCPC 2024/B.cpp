
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

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
ll fact[maxn],inv_fact[maxn];

void pre() {
    fact[0]=1;
    for (ll i=1;i<maxn;i++) {
        fact[i] = i * fact[i-1];
        fact[i] %= mod;
    }

    inv_fact[maxn-1] = inv(fact[maxn-1]);

    for (ll i=maxn-2;i>=0;i--) {
        inv_fact[i] = (i+1) * inv_fact[i+1];
        inv_fact[i] %= mod;
    }
}

ll c(ll k,ll n) {
    if (k > n)return 0;
    ll res = fact[n];
    res *= inv_fact[k];
    res %= mod;
    res *= inv_fact[n-k];
    res %= mod;
    return res;
}



ll pow(ll n) {
    ll res=1,expo=2;
    while (n > 0) {
        if (n&1) {
            res *= expo;
            res %= mod;
        }
        expo *=expo;
        expo %= mod;
        n >>= 1;
    }
    return res;
}

int main() {
    fast();
    pre();
    ll t;
    cin >> t;
    while (t--) {
        ll n,x;
        cin >> n>>x;
        ll o=0,z=0;
        for (ll i = 0; i < n; i++) {
            ll val;
            cin >> val;
            if (val)o++;
            else z++;
        }
        ll res0 = pow(z),res1=0;
        ll k = 0;
        while (k <= o) {
            res1 += c(k,o);
            k += x;
            res1 %= mod;
        }

        cout<<(res1*res0 -1) %mod<<endl;


    }
    return 0;
}
