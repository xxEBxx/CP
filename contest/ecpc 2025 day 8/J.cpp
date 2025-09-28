#include<bits/stdc++.h>

#define aint(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

//typedef long long int;
typedef pair<int, int> ii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<int> vl;
typedef vector<vector<int> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
int sz;
class SegTree {
    struct Node {
        int mn,mx;
        Node() {
            mn = 1e9;
            mx = -1000000000;
        }
    };
    vector <Node> seg;
public:
    SegTree(int n) {
        sz = n;
        seg.resize(4*n + 5);
    }
    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.mn = min(L.mn,R.mn);
        res.mx = max(L.mx,R.mx);
        return res;
    }
    void upd(int idx,int v,int a, int p = 1, int st = 1, int en = sz) {
        if (st == en) {
            if (a==1) seg[p].mx = v;
            else      seg[p].mn = v;
            return;
        }
        int mi = M(st,en);
        if (idx <= mi)
            upd(idx,v,a,L(p), st, mi);
        else
            upd(idx,v,a, R(p), mi + 1, en);
        seg[p] = merge(seg[L(p)], seg[R(p)]);
    }
    Node get(int l, int r, int p = 1, int st = 1, int en = sz) {
        if (l>r) return Node();
        if (l <= st && r >= en) return seg[p];
        if (en < l || st > r) return Node();
        int mi = (st+en)>>1;
        auto Lc = get(l, r, L(p), st, mi);
        auto Rc = get(l, r, R(p), mi+1, en);
        return merge(Lc, Rc);
    }
};

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        vi arr(n);
        vector<int> vals;
        vals.reserve(2*n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            vals.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            vals.push_back(arr[i]+m);
        }
        vector<int> b = vals;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end()); // keep unique values

        vector<int> comp(2*n);
        for (int i = 0; i < 2*n; i++) {
            comp[i] = 1 + int(lower_bound(b.begin(), b.end(), vals[i]) - b.begin());
        }

        int cnt = (int)b.size();
        SegTree st((int)b.size()+2);
        vi r(n, (int)1e9), l(n, -1);
        for (int i=n-1;i>=0;i--) {
            // we find best one bigger than arr[i]+m
            r[i] = min(r[i], st.get(comp[i+n]+1, cnt+1).mn);
            // first smaller than arr[i]
            r[i] = min(r[i], st.get(1, comp[i]-1).mn);
            if (r[i] == (int)1e9) r[i] = n-1;
            st.upd(comp[i], i, 0);
        }
        for (int i=0;i<n;i++) {
            // we find best one bigger than arr[i]+m
            l[i] = max(l[i], st.get(comp[i+n]+1, cnt+1).mx);
            // first smaller than arr[i]
            l[i] = max(l[i], st.get(1, comp[i]-1).mx);
            st.upd(comp[i], i, 1);
        }

        int res=0;
        for (int i=0;i<n;i++) {
            res = max(res, r[i] - l[i]);
        }
        cout<<res-1<<'\n';
    }
    return 0;
}
