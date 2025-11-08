#include<bits/stdc++.h>
 
#define all(v) v.begin(), v.end()
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
 
void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
 
const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;
 
int sz;
#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
class SegTree {
    struct Node {
        int val;
        Node(int v = 0) {
            val = v;
        }
    };
 
 
    vector <Node> seg;
    vector <ii> lazy;
 
 
public:
 
 
    SegTree(int n) {
        sz = n;
        seg.resize(4<<__lg(n));
        lazy.resize(4<<__lg(n), {0,1}); // lazy[p] = 0: means that there is no updates,
        // lazy[p] = v: means that there is an update with value v
    }
 
 
    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = L.val+ R.val;
        return res;
    }
 
 
    void propagate(int p, int st, int en) {
        if (lazy[p].f == 0 && lazy[p].s == 1) return;      // identity

        int fp = lazy[p].f,  sp = lazy[p].s;               // parent transform

        seg[p].val = 2 * fp + sp * seg[p].val;             // apply to this node
        if (st != en) {
            // compose   child_lazy  ∘  parent_lazy
            for (int c : {2*p, 2*p+1}) {
                lazy[c].f = lazy[c].f * sp + fp;           // FIX 2
                lazy[c].s = lazy[c].s * sp;                // FIX 2
            }
        }
        lazy[p] = {0, 1};                                  // reset
    }
 
    void upd_one(ll idx,ll v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            seg[p].val=v;
            return;
        }
        ll mi = M(st,en);
        if (idx <= mi)
            upd_one(idx,v,L(p), st, mi);
        else
            upd_one(idx,v, R(p), mi + 1, en);
        seg[p] = merge(seg[L(p)], seg[R(p)]);
    }

    void upd(int l, int r, int val, int p = 1, int st = 1, int en = sz) {
        propagate(p, st, en);
        if (l <= st && r >= en) {
            lazy[p].f = val-lazy[p].f;
            lazy[p].s *= -1;
            return propagate(p, st, en);
        }
        if (en < l || st > r) return;
 
 
        int mi = (st + en) >> 1;
        upd(l, r, val, p << 1, st, mi);
        upd(l, r, val, p << 1 | 1, mi + 1, en);
 
 
        seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
    }
 
 
    Node get(int l, int r, int p = 1, int st = 1, int en = sz) {
 
        propagate(p, st, en);
        if (l <= st && r >= en) return seg[p];
        if (en < l || st > r) return Node();
        int mi = (st+en)>>1;
        auto L = get(l, r, p << 1, st, mi);
        auto R = get(l, r, p << 1 | 1, mi+1, en);
        return merge(L, R);
    }
};
 
int main() {
    fast();
    freopen("reflection.in",  "r", stdin);
    int t;
    cin >> t;
    int maxi=1e5+2;
    SegTree init(maxi);
    for (int i=1;i<maxi;i++) {
        init.upd_one(i,i-1);
    }
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        SegTree st = init;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            val++;
            int res = st.get(val,val).val;
            cout<<res<<endl;
            st.upd(val,maxi,res);
        }
    }
    return 0;
}