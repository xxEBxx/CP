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

int  main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> proi(n);
        for (ll i=0;i<n;i++) {
            ll right = min(k,n-i-1);
            ll left = min(k,i);
            ll tot = right+left+1;
            ll prob = inv(tot);
            proi[i] = prob;
        }
        vector<ll> prefs(n);
        prefs[0] = proi[0];
        for (int i=1;i<n;i++)
            prefs[i] = (prefs[i-1] + proi[i])%mod;
        vector<ll> out(n);
        for (int i=0;i<n-1;i++) {
            if (i == 0) {
                out[i] = prefs[min(k,n-1)];
                out[n-1] = out[i];
                continue;
            }
            ll rightsum = (prefs[min(i+k,n-1)] - prefs[i-1]);
            ll leftsum = prefs[i-1];
            ll index = max(0LL,i-k-1);
            if (index > 0)
                leftsum =(leftsum - prefs[index])%mod;

            out[i] = (leftsum+rightsum)%mod;
        }
        for (int i=0;i<n;i++)
            cout << out[i]  << " ";
        cout << endl;
    }
    return 0;
}