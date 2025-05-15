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
    return a <= 1 ? a : mod - (mod / a) * inv(mod % a) % mod;
}


int main(){fast();
    ll n,m;cin>>m>>n;

    vi facto(1001,0);
    facto[0]=facto[1]=1;
    for(ll i=2;i<1001;i++){
        facto[i] = i*facto[i-1];
        facto[i] %= mod;
        //cout<<facto[i]<<" ";
    }

    ll res=0;
    for (ll l = 1; l <= n; l++) {
        for (ll i = max(0ll, l - m); i <= l; i++) {
            //i is the number of 0's
            ll choose = facto[l] * inv(facto[i]) % mod * inv(facto[l - i]) % mod; // C(1,n) just reordering the
            ll perm = facto[m] * inv(facto[m - (l - i)]) % mod; // P(m, l - i)
            res = (res +choose * perm) % mod;
        }
    }
    cout<<res<<endl;

    return 0;
}