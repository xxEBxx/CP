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
const ll mod = (ll) 998244353;

ll pow(ll n) {
    ll res=1,expo=2;
    while (n>0) {
        if (n&1) {
            res *= expo;
            res%=mod;
        }
        expo *= expo;
        expo %= mod;
        n/=2;
    }
    return res;
}

int main() {
    fast();
        ll n;
        cin >> n;
        vi arr(n);
        map<ll,ll> count;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            count[arr[i]]++;
        }
        ll res=1;
        for (auto elem : count) {
            res += elem.s*(elem.s-1)/2;
            res %= mod;
        }
        cout<<res<<endl;

    return 0;
}
