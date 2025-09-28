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

LineContainer hull[maxn];
ll ans[maxn],dp[maxn],a[maxn],b[maxn];
vvi g(maxn);

void dfs(ll i,ll p) {
    bool leaf = (i != 1 && g[i].size() == 1);

    for (ll c : g[i]) {
        if (c==p)continue;
        dfs(c,i);
        //if (hull[i].size() < hull[c].size() )swap(hull[i],hull[c]);
        for (auto  ln : hull[c])
            hull[i].add(ln.k,ln.m);
    }
    if (leaf)
        dp[i] = 0;
    else
        dp[i] = hull[i].query(a[i]);
    hull[i].add(-b[i],dp[i]);
}

int main() {
    fast();
    ll n;  cin >> n;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    for (ll i = 1; i <= n; ++i) cin >> b[i];
    for (ll i = 1; i < n; ++i) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    for (ll i=1;i<=n;i++)
        cout<<-dp[i]<<' ';
    cout<<endl;
    return 0;
}
