//  ─────────────────────────────────────────────────────────────
//  ECPC  –  Problem “Reflection”
//  solution: lazy segment-tree with affine-flip tags
//  by ChatGPT (Aug 2025)
//  ─────────────────────────────────────────────────────────────
#include <bits/stdc++.h>
using namespace std;
using  ll = long long;

struct SegTree {
    struct Tag { bool flip; ll add; };          // y ← (flip? -y : y) + add

    int n;                                      // power of two ≥ MAX_X+1
    vector<char> lazyFlip;                      // 0 / 1
    vector<ll>   lazyAdd;

    explicit SegTree(int N) {
        n = 1;  while (n < N) n <<= 1;
        lazyFlip.assign(2 * n, 0);
        lazyAdd .assign(2 * n, 0);
    }
    void reset() {
        fill(lazyFlip.begin(), lazyFlip.end(), 0);
        fill(lazyAdd .begin(), lazyAdd .end(), 0);
    }

    /* Combine “apply this tag to an entire node”.                */
    void apply(int v, bool flip, ll add) {
        if (!flip && add == 0) return;
        if (flip) {
            lazyFlip[v] ^= 1;
            lazyAdd [v]  = -lazyAdd[v] + add;
        } else {
            lazyAdd[v]  += add;
        }
    }
    /* Push pending tag to the two children.                      */
    void push(int v) {
        if (lazyFlip[v] || lazyAdd[v]) {
            apply(v<<1    , lazyFlip[v], lazyAdd[v]);
            apply(v<<1|1  , lazyFlip[v], lazyAdd[v]);
            lazyFlip[v] = 0;
            lazyAdd [v] = 0;
        }
    }

    /* Point-query: current y-value at x == pos.                   */
    ll query(int v, int l, int r, int pos) {
        if (l + 1 == r)        // reached the leaf
            return (lazyFlip[v] ? -(ll)pos : (ll)pos) + lazyAdd[v];

        push(v);
        int m = (l + r) >> 1;
        return (pos < m ? query(v<<1, l, m, pos)
                        : query(v<<1|1, m, r, pos));
    }
    inline ll query(int pos) { return query(1, 0, n, pos); }

    /* Range-update: apply “y ← –y + c” on suffix [ql, n).         */
    void update(int v, int l, int r, int ql, ll c) {
        if (r <= ql) return;               // segment completely left of suffix
        if (l >= ql) {                     // segment fully inside suffix
            apply(v, true, c);
            return;
        }
        push(v);
        int m = (l + r) >> 1;
        update(v<<1   , l, m, ql, c);
        update(v<<1|1 , m, r, ql, c);
    }
    inline void reflect_suffix(int pos, ll y) {   // c = 2*y
        update(1, 0, n, pos, 2*y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MAX_X = 100000 + 1;      // xi ∈ [0, 1e5]

    SegTree st(MAX_X + 2);                 // one tree reused for all cases
    ifstream cin("reflection.in");
    int T;  cin >> T;
    while (T--) {
        st.reset();
        int Q;  cin >> Q;
        while (Q--) {
            int x;  cin >> x;
            ll y = st.query(x);
            cout << y << '\n';
            st.reflect_suffix(x, y);
        }
    }
    return 0;
}
