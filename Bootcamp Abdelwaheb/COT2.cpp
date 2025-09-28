#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll maxn = 40000 + 10;
const ll mod = (ll) 1e9 + 7;

vvi g(maxn);
vi val(maxn,0),tin(maxn, -1), depth(maxn, 0), tout(maxn, -1);
vi order;

vvi st(maxn, vi(20, -1));
vi freq;

void dfs(ll i, ll p) {
    order.push_back(i);
    tin[i] = order.size() - 1;
    tout[i] = order.size() - 1;

    depth[i] = 1 + depth[p];
    st[i][0] = p;

    for (ll c : g[i]) {
        if (c == p) continue;
        dfs(c, i);
    }

    order.push_back(i);
    tout[i] = order.size() - 1;
}

ll lift(ll a, ll k) {
    for (ll i = 0; i < 20; i++) {
        if (k >> i & 1) {
            a = st[a][i];
        }
    }
    return a;
}

ll lca(ll a, ll b) {
    if (depth[a] > depth[b])
        swap(a, b);

    ll k = depth[b] - depth[a];
    b = lift(b, k);

    if (a == b) return a;

    for (ll j = 19; j >= 0; j--) {
        if (st[a][j] != st[b][j]) {
            a = st[a][j];
            b = st[b][j];
        }
    }
    return st[a][0];
}

ll n, q, sqt;
struct Query {
    ll l, r, idx, extra;
};

bool comp(Query a, Query b) {
    if (a.l / sqt != b.l / sqt)
        return a.l < b.l;
    return a.r < b.r;
}

ll distinct_count = 0;
vi all_val(maxn, 0), exist(maxn, 0),comp_val(maxn);;

void toggle(ll idx) {
    ll node = order[idx];
    if (exist[node]) {
        freq[comp_val[node]]--;
        if (freq[comp_val[node]] == 0)
            distinct_count--;
    } else {
        freq[comp_val[node]]++;
        if (freq[comp_val[node]] == 1)
            distinct_count++;
    }
    exist[node] = 1 - exist[node];
}

int main() {
    fast_io();
    cin >> n >> q;
    sqt = sqrt(2 * n) + 1;

    for (ll i = 1; i <= n; i++) {
        cin >> val[i];
        all_val[i - 1] = val[i];
    }

    sort(all(all_val));
    all_val.erase(unique(all(all_val)), all_val.end());
    for (ll i = 1; i <= n; i++) {
        comp_val[i] = lower_bound(all(all_val), val[i]) - all_val.begin();
    }

    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1);

    for (ll j = 1; j < 20; j++) {
        for (ll i = 1; i <= n; i++) {
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
    }

    vector<Query> queries(q);
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        ll p = lca(a, b);
        if (tin[a] > tin[b]) swap(a, b);
        ll L, R, extra = -1;
        if (p == a) {
            L = tin[a];
            R = tin[b];
        } else {
            L = tout[a];
            R = tin[b];
            extra = p;
        }
        queries[i] = {L, R, i, extra};
    }

    sort(all(queries), comp);
    vi res(q);
    ll x = 0, y = -1;

    ll max_comp_val = all_val.size();
    freq.resize(max_comp_val+1, 0);

    for (ll i = 0; i < q; i++) {
        ll l = queries[i].l;
        ll r = queries[i].r;
        ll extra = queries[i].extra;

        while (y < r) {
            y++;
            toggle(y);
        }
        while (y > r) {
            toggle(y);
            y--;
        }
        while (x < l) {
            toggle(x);
            x++;
        }
        while (x > l) {
            x--;
            toggle(x);
        }

        if (extra != -1) {
            freq[comp_val[extra]]++;
            if (freq[comp_val[extra]] == 1)
                distinct_count++;
        }

        res[queries[i].idx] = distinct_count;

        if (extra != -1) {
            freq[comp_val[extra]]--;
            if (freq[comp_val[extra]] == 0)
                distinct_count--;
        }
    }

    for (ll i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}