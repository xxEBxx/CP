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

bool comp(ii a,ii b) {
    if (a.f != b.f)return a.f < b.f;
    return a.s < b.s;
}
struct block {
    ll l,mxb,best;
    //best is the best of this block
};

int main(){fast();
    ll n;cin>>n;
    vector<ll> dp(n+1,0);
    vector<pair<ll,ll>> elem(n+1,{0,0});
    for(ll i=1;i<=n;i++)cin>>elem[i].f>>elem[i].s;
    sort(all(elem),comp);

    vector<block> arr;
    for (ll i=1;i<=n;i++) {
        block curr = {i,elem[i].s,dp[i-1] + elem[i].f*elem[i].s};
        while (!arr.empty() && arr.back().mxb <= curr.mxb) {
            //we merge
            curr.l = arr.back().l;
            curr.best = min(curr.best , dp[arr.back().l-1] + elem[i].f * elem[i].s);
            arr.pop_back();
        }
        arr.push_back(curr);
        dp[i] = curr.best;
    }
    cout<<dp[n]<<endl;
    return 0;
}







