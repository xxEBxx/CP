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
const ll mod  = (ll) 1e9 + 7;
const ll PHI  = mod - 1;

ll powmod(ll a,ll b) {
    ll res=1%mod, fact=a%mod;
    while (b>0) {
        if (b&1) { res = (res * fact) % mod; }
        fact = (fact * fact) % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll a) { return powmod(a, mod-2); }

// reduce a big decimal string modulo m
ll mod_from_string(const string &s, ll m){
    ll r=0;
    for(char c: s) r = (r*10 + (c-'0')) % m;
    return r;
}
inline bool is_even_str(const string &s){ return ((s.back()-'0') & 1) == 0; }

int main() {
    fast();

    string ns, ks;               // read as BIG integers (strings)
    cin >> ns >> ks;

    // If n is even → probability is 0
    if (is_even_str(ns)) {
        cout << 0 << '\n';
        return 0;
    }

    ll kmod = mod_from_string(ks, mod);
    // Avoid inv(0): if k ≡ 0 mod M, then for n>1 the fraction is 0; for n=1 it's 1.
    if (kmod == 0) {
        cout << (ns == "1" ? 1 : 0) << '\n';
        return 0;
    }

    // Exponents:
    // e2 = (n-1) mod (mod-1)
    ll n_mod_phi = mod_from_string(ns, PHI);
    ll e2 = (n_mod_phi - 1 + PHI) % PHI;

    // t = ((n-1)/2) mod (mod-1) using n mod 2*(mod-1)
    ll two_phi = 2 * PHI;
    ll n_mod_2phi = mod_from_string(ns, two_phi);
    ll num = (n_mod_2phi - 1 + two_phi) % two_phi; // odd → safe to halve
    ll t = num / 2;

    // res = (k-1)^t * inv(k^(n-1)) mod M
    ll km1 = (kmod - 1 + mod) % mod;
    ll res = inv(powmod(kmod, e2));
    res = (res * powmod(km1, t)) % mod;

    cout << res << '\n';
    return 0;
}
