#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e5+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

vector<int> arr;
#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;
class SegTree {
    struct Node {
        ll l,h,s;
        Node() {
            l = 1e18;//you can make it an array here or 2 values or a small array...
            h = -1e18;
            s=0;//s is also a max
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
        res.h = max(L.h , R.h);
        res.l = min(L.l,L.h);
        res.s = max(L.s,R.s);
        return res;
    }
    void upd(ll idx,ll v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            seg[p].s=v;// v is it solvable ?
            seg[p].h=arr[st];
            seg[p].l=arr[st];
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

int main(){fast();
    ll n,k,d;cin>>n>>k>>d;
    arr.resize(n+1,0);
    for(int i=1;i<1+n;i++){
        cin>>arr[i];
    }
    sort(all(arr));

    SegTree st(1e5);
    vector<int> dp(n+1,0);
    ll h=arr[k],l=arr[1];
    for(ll i=1;i<=k;i++){
        if(arr[i]-l>d || h-arr[i]>d){
            cout<<"NO"<<endl;
            return 0;
        }
        dp[i]=1;
        st.upd(i,1);
    }
    for(ll i=k+1;i<=n;i++){
        auto elem = st.get(1,i-1-k);
        if(elem.s==1 && elem.h-elem.l<=d){
            dp[i]=1;
        }
        st.upd(i,dp[i]);
    }
    if(dp[n])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}