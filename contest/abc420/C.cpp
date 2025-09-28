
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


#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;
class SegTree {
    struct Node {
        ll val,a,b;
        Node() {
            val = 0;//you can make it an array here or 2 values or a small array...
            a=0;b=0;
        }
    };
    vector <Node> seg;
public:
    SegTree(ll n) {
        sz = n;
        seg.resize(4<<__lg(n));
    }
    Node merge(Node &L, Node &R) {
        Node res = Node();
        res.val = L.val + R.val;
        return res;
    }
    void upd(ll idx,ll v,ll a, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            if (a==1)seg[p].a=v;
            else seg[p].b=v;
            seg[p].val=min(seg[p].a,seg[p].b);
            return;
        }
        ll mi = M(st,en);
        if (idx <= mi)
            upd(idx,v,a,L(p), st, mi);
        else
            upd(idx,v,a, R(p), mi + 1, en);
        seg[p] = merge(seg[L(p)], seg[R(p)]);
    }
    Node get(ll l, ll r, ll p = 1, ll st = 1, ll en = sz) {
        if (l <= st && r >= en) return seg[p];
        if (en < l || st > r) return Node();
        ll mi = (st+en)>>1;
        auto L = get(l, r, L(p), st, mi);
        auto R = get(l, r, R(p), mi+1, en);
        return merge(L, R);
    }
};


int main() {
    fast();
    ll n,q;
    cin>>n>>q;
    vi a(n+1),b(n+1);
    SegTree st(n+1);
    for (ll i=1;i<=n;i++) {
        cin >> a[i];
        st.upd(i,a[i],1);
    }
    for (ll i=1;i<=n;i++){
        cin >> b[i];
        st.upd(i,b[i],0);
    }

    for (ll i=0;i<q;i++) {
        char c;
        ll x,v;
        cin>>c>>x>>v;
        st.upd(x,v,(c=='A'?1:0));
        cout<<st.get(1,n).val<<endl;
    }
    return 0;
}
