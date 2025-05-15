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
const ll mod=(ll)998244353;

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main(){fast();

    vector<ll> facto(maxn),inv_facto(maxn);
    facto[0]=1;

    for(ll i=1;i<maxn;i++){
        facto[i]=facto[i-1]*i;
        facto[i]%=mod;
    }

    inv_facto[maxn-1] = inv(facto[maxn-1]);
    inv_facto[0] = 1;
    for(ll i=maxn-2 ; i>0 ; i--){
        inv_facto[i] = inv_facto[i+1]*(i+1);
        inv_facto[i] %= mod;
    }

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll res=0;
        for(ll i=1;i<=n;i++){
            res += facto[n] * inv_facto[n-i];
            res %= mod;
        }
        cout<<res<<endl;
    }
    return 0;
}