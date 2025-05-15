#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

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
        lazy.resize(4<<__lg(n), -1); // lazy[p] = 0: means that there is no updates,
        // lazy[p] = v: means that there is an update with value v
        //let's store in lazy[i] the index from where we started

    }


    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = min(L.val, R.val);
        return res;
    }


    void propagate(int p, int st, int en) {
        if (lazy[p] == 0) return;
        seg[p].val = lazy[p];
        if (st != en) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
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




int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    return 0;
}