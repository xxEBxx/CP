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
class SegTree {
    struct Node {
        int val;
        Node(int v = 2e9) {
            val = v;
        }
    };


    vector <Node> seg;
    vector <int> lazy;


public:


    SegTree(int n) {
        sz = n;
        seg.resize(4<<__lg(n));
        lazy.resize(4<<__lg(n), 0); // lazy[p] = 0: means that there is no updates,
        // lazy[p] = v: means that there is an update with value v
    }


    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = L.val + R.val;
        return res;
    }


    void propagate(int p, int st, int en) {
        if (lazy[p] == 0) return;
        seg[p].val ^= 1;
        if (st != en) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }


    void upd(int l, int r, int val, int p = 1, int st = 1, int en = sz) {
        propagate(p, st, en);
        if (l <= st && r >= en) {
            lazy[p] ^= 1;
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
    int n,k;
    cin>>n>>k;
    vi arr(k);
    for (int i=0;i<k;i++) {
        cin>>arr[i];
    }
    SegTree st(n+1);
    int mxi=0,mni=0,mx=arr[0],mn=arr[1];
    vi added(n+1,0);
    for (int i=0;i<k;i++) {
        if (arr[i] > mx) {
            mxi = i;
            mx=arr[i];
        }
        if (arr[i] < mn) {
            mni = i;
            mn = arr[i];
        }
        st.upd(mn,mx,1);
    }


    return 0;
}
