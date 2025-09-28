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
const ll mod = 998244353;
ll fact[maxn],inv_fact[maxn];
ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void pre() {
    fact[0]=1;
    for (ll i=1;i<maxn;i++) {
        fact[i] = i*fact[i-1];
        fact[i] %=mod;
    }
    inv_fact[maxn-1] = inv(fact[maxn-1]);
    for (ll i=maxn-2;i>=0;i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1);
        inv_fact[i] %=mod;
    }
}
ll c(ll k,ll n) {
    ll res  = fact[n];
    res *= inv_fact[k];
    res %= mod;
    res *= inv_fact[n-k];
    res %= mod;
    return res;
}
int main() {
    fast();
    pre();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi arr(n);
        ll tot=0;
        ll top = (n-1)/2;
        ll allowed = 2;
        if (n&1)allowed=1;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            tot+=arr[i];
            if (i > (n-1)/2 && arr[i]>0)
                tot=n+1;
        }
        if (tot != n) {
            cout<<0<<endl;
            continue;
        }
        ll res=1;
        if (arr[top] > allowed)res=0;
        if (allowed == 2 && arr[top]==1)res=2;
        allowed -= arr[top];

        for (ll i = top-1;i>=0;i--) {
            if (res==0)break;
            allowed += 2;
            if (arr[i] > allowed) res=0;
            res *= c(arr[i],allowed);
            res %= mod;
            allowed -= arr[i];
        }
        cout<<res<<endl;

    }
    return 0;
}
