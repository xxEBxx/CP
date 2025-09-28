
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
        Node(int v = 0) {
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
        res.val = L.val+ R.val;
        return res;
    }


    void propagate(int p, int st, int en) {
        if (lazy[p] == 0) return;
        seg[p].val += lazy[p]*(en - st + 1);
        if (st != en) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }


    void upd(int l, int r, int val, int p = 1, int st = 1, int en = sz) {
        propagate(p, st, en);
        if (l <= st && r >= en) {
            lazy[p] = val;
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
    int n,m;
    cin>>n>>m;
    vi arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        arr[i] %= (m+1);
        if (arr[i]>0)
            arr[i]=1;
    }
    vi ps(n,0),ss(n,0);
    ps[0] = arr[0];
    ss[n-1]=arr[n-1];
    for (int i=1;i<n;i++)
        ps[i]=ps[i-1]+arr[i];
    for (int i=n-2;i>=0;i--)
        ss[i]=ss[i+1]+arr[i];

    SegTree tree(n);
    for (int i=0;i<n;i++) {
        if (ss[i]!=0)
             tree.upd(1,ss[i],1);
        if (arr[i]==0) {
            if (ps[i]!=0)
                tree.upd(1,ps[i],1);
        }

    }


    for (int i=1;i<=n;i++) {
        cout << tree.get(i,i).val<< " ";
    }
    cout << endl;

    return 0;
}
