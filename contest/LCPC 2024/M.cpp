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

const ll maxn = (ll) 1e5 + 7;
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

int main() {
    fast();
    pre();
    ll n,k;
    cin>>n>>k;
//from ai we choose (min(k,ai)-1) from ai person from each group
//then its normal stars and bars and stars
    vi arr(n);
    ll res = 1,total=0;
    for (ll i=0;i<n;i++) {
        cin>>arr[i];
        ll taken = min(k,arr[i])-1;
        res *= c(taken,arr[i]);
        res %= mod;
        total += taken;
    }

    res *= c(k,total);
    cout<<res%mod<<endl;

    return 0;
}
