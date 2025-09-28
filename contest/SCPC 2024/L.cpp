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

ll expo(ll n) {
    ll res=1,expo=2;
    while(n>0){
        if (n&1) {
            res *= expo;
            res %= mod;
        }
        n>>=1;
        expo *= expo;
        expo %= mod;
    }
    return res;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n,s,m;
        cin>>n>>s>>m;

        if (n&1) {
            ll res = expo(s)-1;
            while (res<0)res+=mod;
            cout<<res<<endl;
        }
        else {
            if (s==m) {
                cout<<0<<endl;
                continue;
            }

            ll res = expo(s) - 1;
            while (res < 0)res += mod;
            ll diff = expo(max((ll)0,max((ll)0,s-n) - n*(s - m-1))) - 1;
            while (diff < 0)diff += mod;
            res -= diff;
            while (res < 0) res += mod;
            cout << res << endl;

        }
    }
    return 0;
}

