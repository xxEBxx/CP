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


const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;


void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};


int main(){fast();
    ll n;cin>>n;
    vector<ll> a(n+1,0),ps(n+1,0),s(n+1,0),dp(n+1,0);
    for(ll i=1;i<=n;i++)cin>>a[i];
    //for(ll i=0;i<n;i++)cin>>b[i];
    LineContainer cht;
    cht.add(0,-1e18);
    for (int i =1;i<=n;i++) {
        ps[i] = ps[i-1] + a[i];
        s[i] = s[i-1] + i * a[i];
    }
    ll res = s[n];
    for (int i=1;i<=n;i++) {
        dp[i] = s[n]-ps[i] + cht.query(i);
        cht.add(a[i],ps[i]-i*a[i]);
        res = max(res,dp[i]);
    }
    LineContainer cht2;
    cht2.add(0, -1e18);

    for (ll j = n; j >= 1; --j) {

        long long cand = s[n] - ps[j-1] + cht2.query(j);
        res = max(res, cand);

        cht2.add(a[j], ps[j-1] - 1LL*j * a[j]);
    }

    cout<<res<<endl;


    return 0;
}