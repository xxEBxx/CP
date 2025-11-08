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
struct Node {
    bitset<1001> v;
    Node() {

    }
};
Node temp;
int sz;
class SegTree {



    vector <Node> seg;
    vector <bitset<1001>> lazy;


public:


    SegTree(int n) {
        sz = n;
        seg.resize(4<<__lg(n));
        lazy.resize(4<<__lg(n), bitset<1001>()); // lazy[p] = 0: means that there is no updates,
        // lazy[p] = v: means that there is an update with value v
    }


    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.v = L.v & R.v;
        return res;
    }


    void propagate(int p, int st, int en) {
        if (lazy[p] == 0) return;
        seg[p].v |= lazy[p];
        if (st != en) {
            lazy[2*p] |= lazy[p];
            lazy[2*p+1] |= lazy[p];
        }
        lazy[p] = 0;
    }


    void upd(int l, int r, bitset<1001> val, int p = 1, int st = 1, int en = sz) {
        propagate(p, st, en);
        if (l <= st && r >= en) {
            lazy[p] |= val;
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
        if (en < l || st > r) return temp;

        int mi = (st+en)>>1;
        auto L = get(l, r, p << 1, st, mi);
        auto R = get(l, r, p << 1 | 1, mi+1, en);
        return merge(L, R);
    }
};

int main() {
    fast();
    int n,q;
    cin >> n>>q;
    temp.v.flip();
    SegTree st(n+1);
    for (int i = 0; i < q; i++) {
        int t;cin>>t;
        if (t==1) {
            int l,r,x;
            cin>>l>>r>>x;
            bitset<1001> c;
            c.set(x);
            st.upd(l,r,c);
        }
        else {
            int l,r;
            cin>>l>>r;
            auto res = st.get(l,r).v;
            cout<<res.count()<<endl;
        }
    }



    return 0;
}
