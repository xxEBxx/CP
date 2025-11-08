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
        ll val,mn,mx,res;
        Node() {
            val=1e9;
            res=0;
            mn=1e9;
            mx=-1e9;
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
        if (L.val < R.val) {
            res = L;
        }
        else if (L.val > R.val) {
            res = R;
        }
        else {
            res.val = R.val;
            res.mn = min(L.mn,R.mn);
            res.mx = max(L.mx,R.mx);
            res.res =L.res+R.res;
            ll dist  = R.mn-L.mx-1;
            res.res += dist*(dist+1)/2;
        }
        return res;
    }
    void upd(ll idx,ll v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            seg[p].val = v;
            seg[p].mn = st;
            seg[p].mx = st;
            seg[p].res = 0;
            return;
        }
        ll mi = M(st,en);
        if (idx <= mi)
            upd(idx,v,L(p), st, mi);
        else
            upd(idx,v, R(p), mi + 1, en);
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
        ll n;
        cin >> n;
        vi arr(n+1);
        SegTree st(n+1);
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];

            st.upd(i,arr[i]);
        }

        ll q;cin >>q;
        for (ll i=0;i<q;i++) {
            ll l,r;cin>>l>>r;
            auto res = st.get(l,r);

            ll dist =r-l+1;
            ll all_poss = (dist+1)*dist/2;
            ll invalid = (r-res.mx+1) * (res.mn-l+1) + (res.mn-l+1)*(res.mn-l)/2 + (r-res.mx+1)*(r-res.mx)/2;
            cout<<all_poss - invalid - res.res<<endl;

    }
    return 0;
}