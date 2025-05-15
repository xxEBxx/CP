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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;
class SegTree {
    struct Node {
        pair<ll,ll> val;
        Node() {
            val  = {0,0};
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
        if(L.val.f == R.val.f){
            res.val.f=R.val.f;
            res.val.s = min(R.val.s,L.val.s);
        }
        else if(L.val.f > R.val.f){
            res =L;
        }
        else {
            res =R;
        }
        return res;
    }
    void upd(ll idx,pair<ll,ll> v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            if(seg[p].val.f  < v.f){
                seg[p].val = v;
            }
            else if(seg[p].val.f  == v.f){
                seg[p].val.s = min(seg[p].val.s,v.s);
            }

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

struct lec{
    ll l,r,c;
};
bool comp(lec a,lec b){
    if(a.r == b.r)
        return a.l < b.l;
    return a.r < b.r ;
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<lec> arr(n);
        //ugh we need to concize the sqaize
        set<ll> all;
        map<ll,ll> compress;
        for(ll i=0;i<n;i++){
            cin>>arr[i].l>>arr[i].r>>arr[i].c;
            all.insert(arr[i].l);
            all.insert(arr[i].r);
        }
        ll counter =0 ;
        for(auto elem : all){
            counter++;
            compress[elem] = counter;
        }

        for(ll i=0;i<n;i++){
            arr[i].l = compress[arr[i].l];
            arr[i].r = compress[arr[i].r];
        }

        sort(all(arr),comp);

        vector<pair<ll,ll>> dp(n);

// the segment tree structure is : end time will give the
// pair of best time in that llerval and best coffee to have
        SegTree st(counter);

        for(ll i=0;i<n;i++){
            auto res = st.get(1, arr[i].l-1 );
            dp[i].f = res.val.f+1;
            dp[i].s = max(arr[i].c,res.val.s);
            st.upd(arr[i].r,dp[i]);
        }

        ll res1=0,res2=1e9;
        for(ll i=0;i<n;i++){
            if(dp[i].f > res1){
                res1 = dp[i].f;
                res2 = dp[i].s;
            }
            else if(dp[i].f == res1 ){
                res2 = min(res2,dp[i].s);
            }
        }
        cout<<res1<<" "<<res2<<endl;
    }
    return 0;
}