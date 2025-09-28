

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

int main() {
    fast();
    ll n;
    cin>>n;
    unordered_map<ll,ll> m;
    for (ll i=1;i<=n;i++) {
        ll val;cin>>val;
        m[(i+val)%n]++;
    }
    ll res=n;
    for (auto elem : m) {
        res += (elem.s-1)*elem.s;
    }
    cout<<res<<endl;
    return 0;
}
