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

bool comp(ii a,ii b) {
    return a.f<b.f;
}


struct Tree {
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b; } // (any associative fn)
    vector<T> s; ll n;
    Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
    void add(ll pos, T delta) {
        // assumes the leaf at pos already has a valid value (not ll_MIN)
        for (s[pos += n] += delta; pos >>= 1; )
            s[pos] = f(s[pos<<1], s[pos<<1|1]);
    }
    T query(ll b, ll e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};


int main() {
    fast();
    const ll MAXN = 1'000'000; // sum n ≤ 1e6
    static vector<ll> pow2(MAXN+1,1);
    static bool built=false;
    if(!built){
        for (ll i=1;i<=MAXN;i++) pow2[i] = (pow2[i-1]*2LL) % mod;
        built=true;
    }

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ii> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i].f;
        }
        for (ll i = 0; i < n; i++) {
            cin >> arr[i].s;
        }
        // collect all values
        vector<long long> vals;
        vals.reserve(2LL*n);
        for (int i=0;i<n;i++){
            vals.push_back(arr[i].f);
            vals.push_back(arr[i].s);
        }
        // sort & dedup
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        // map in O(log M) per value
        for (int i=0;i<n;i++){
            arr[i].f = int(lower_bound(vals.begin(), vals.end(), arr[i].f) - vals.begin()) + 1; // 1-based
            arr[i].s = int(lower_bound(vals.begin(), vals.end(), arr[i].s) - vals.begin()) + 1;
        }
        int cnt = (int)vals.size(); // total ranks
        Tree st(cnt+2);
        for (ll i = 0; i < n; ++i) st.add(arr[i].s - 1, +1);

        sort(all(arr),comp);

        long long ans = 0;
        for (ll i=0; i<n; ) {
            ll A = arr[i].f;
            ll j = i;
            while (j<n && arr[j].f == A) j++;

            ll ge = (A-1 >= 0) ? st.query(0, A-1) : 0;   // counts b_rank < A ✅

            ll eq_good = 0; // in this block with b < A
            for (ll t=i; t<j; ++t) if (arr[t].s < A) ++eq_good;

            ll gt = ge - eq_good; // those with a > A and b < A

            ll add = pow2[ge] - pow2[gt];
            if (add < 0) add += mod;
            ans += add; if (ans >= mod) ans -= mod;

            for (ll t=i; t<j; ++t) st.add(arr[t].s - 1, -1); // remove same index ✅


            i = j;
        }

        cout << ans % mod << '\n';
    }
    return 0;
}

