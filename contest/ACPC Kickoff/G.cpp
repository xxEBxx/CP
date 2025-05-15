#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n);
        ll total =0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            total+=arr[i];
            total %= mod;
        }
        ll res = total;//for the 0 step
        res%=mod;
        for(ll i=1;i<n;i++){
            ll g = (n/gcd(n,i)) % mod;
            g = (total * g)%mod;
            res += g;
            res%=mod;
        }
        ll denom = n*n;
        denom %= mod;
        res *= inv(denom);
        res%=mod;
        cout<<res<<endl;

    }
    return 0;
}