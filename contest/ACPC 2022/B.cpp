#include <bits/stdc++.h>
typedef long long ll;
const ll MAXN = 1e6 + 2;
const ll mod = 1e9+7;
using namespace std;

ll inv(ll a) {
    return a <= 1 ? a : mod - (mod / a) * inv(mod % a) % mod;
}

ll f[MAXN];
ll invfat[MAXN];

void calc() {
    f[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    invfat[MAXN - 1] = inv(f[MAXN - 1]);
    for (ll i = MAXN - 2; i >= 0; i--) {
        invfat[i] = invfat[i + 1] * (i + 1) % mod;
    }
}

ll ncr(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    ll ans = f[n] * invfat[k] % mod * invfat[n - k] % mod;
    return ans;
}

ll catalan(ll x) {
    ll ans = ncr(2 * x, x) * inv(x + 1) % mod;
    return ans;
}

int main() {
    calc(); // Initialize factorials and inverse factorials
    int n;
    bool f=true;
    while(cin>>n){
        if(!f){
            cout<<endl;
        }
        else{
            f=false;
        }
        cout<<catalan(n)<<endl;
    }
    return 0;
}
