#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;
class SegTree {
    struct Node {
        ll val;
        Node() {
            val = 0;//you can make it an array here or 2 values or a small array...
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
    void upd(ll idx,ll v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            seg[p].val=v;
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
    ll n,k; cin >> n>>k;
    vector<SegTree> st;
    for(ll i=1;i<=12;i++) {
        SegTree v(1e5+5);
        st.push_back(v);
    }
    vi arr(n+1,0);
    for (ll i = 1; i <= n; i++) {
        cin>>arr[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(12,0));

    for(ll i=1;i<=n;i++){
        st[1].upd(arr[i], 1);
        for(ll j=2;j<=11;j++){
            //for 2 we want to know number of elments smaller than a[i]
            dp[i][j]=st[j-1].get(1,arr[i]-1).val;//smaller with size j-1
            st[j].upd(arr[i],dp[i][j]);
        }
    }
    cout<<st[k+1].get(1,n).val<<endl;

    return 0;
}
