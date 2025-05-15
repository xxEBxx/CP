#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn = (int)1e6 + 7;
const int mod = (int)1e9 + 7;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

#define L(i) (i << 1)
#define R(i) (i << 1) + 1
#define M(i, j) ((i + j) >> 1)

class SegTree {
    struct Node {
        ll best, pre, suff, total;
        Node() {
            best = LLONG_MIN; // Handle negative values
            pre = LLONG_MIN;
            suff = LLONG_MIN;
            total = 0;
        }
    };

public:
    vector<Node> seg;
    ll sz;

    SegTree(ll n) {
        sz = n;
        seg.resize(4 * n);
    }

    Node merge(Node &L, Node &R) {
        Node res;
        res.total = L.total + R.total;
        res.pre = max(L.pre, L.total + R.pre);
        res.suff = max(R.suff, L.suff + R.total);
        res.best = max({L.best, R.best, L.suff + R.pre, res.pre, res.suff, 0LL}); // Ensure empty subarray is considered
        return res;
    }

    void upd(ll idx, ll v, ll p = 1, ll st = 0, ll en = -1) {
        if (en == -1) en = sz - 1; // 0-based indexing
        if (st == en) {
            seg[p].best = max(v, 0LL); // Ensure empty subarray is considered
            seg[p].pre = max(v, 0LL);
            seg[p].suff = max(v, 0LL);
            seg[p].total = v;
            return;
        }
        ll mi = M(st, en);
        if (idx <= mi)
            upd(idx, v, L(p), st, mi);
        else
            upd(idx, v, R(p), mi + 1, en);
        seg[p] = merge(seg[L(p)], seg[R(p)]);
    }
};

int main() {
    fast();
    int n, m;
    cin >> n >> m;
    SegTree st(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.upd(i, val); // 0-based indexing
    }
    for (int i = 0; i < m; i++) {
        int index, val;
        cin >> index >> val;
        st.upd(index - 1, val); // Convert to 0-based indexing
        cout << st.seg[1].best << endl;
    }

    return 0;
}