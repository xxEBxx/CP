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

#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;
vi arr;
class SegTree {
    struct Node {
        ll first,last;
        Node() {
            //best for first element of segment
            //best for last  element of segment
        }
    };
    vector <Node> seg;
public:
    SegTree(ll n) {
        sz = n;
        seg.resize(4<<__lg(n));
    }
    Node merge(Node &L, Node &R,ll sizeL,ll sizeR) {
        Node res = Node();
        res.first = min(L.first ,R.first + sizeL);//size of L
        res.last = min(R.last , L.last + sizeR);
        return res;
    }

    void upd(ll idx,ll v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            seg[p].first=arr[en];
            seg[p].last=arr[en];
            return;
        }
        ll mi = M(st,en);
        if (idx <= mi)
            upd(idx,v,L(p), st, mi);
        else
            upd(idx,v, R(p), mi + 1, en);
        seg[p] = merge(seg[L(p)], seg[R(p)],mi+1-st,en-mi);
    }

    Node get(ll l, ll r, ll p = 1, ll st = 1, ll en = sz) {
        if (l <= st && r >= en) return seg[p];
        if (en < l || st > r) return Node();
        ll mi = (st+en)>>1;
        auto L = get(l, r, L(p), st, mi);
        auto R = get(l, r, R(p), mi+1, en);

        return merge(L, R,mi+1-st,en-mi);
    }
};


int main(){fast();
    int n,m;cin>>n>>m;
    arr.assign(n+1,0);
    SegTree st(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.upd(i,arr[i]);
    }
    for(int i=0;i<m;i++){
        int t;cin>>t;
        if(t==1){
            int index,val;cin>>index>>val;
            st.upd(index,val);
        }
        else{
            int val;
            cin>>val;
            cout<<min(st.get(1,val).last , st.get(val,n).first)<<endl;

        }
    }


    return 0;
}