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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

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
       res.val = max(L.val , R.val);
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

int main(){fast();
    int n,k;cin>>n>>k;
    vector<int> arr(n),compress_helper(n);
    unordered_map<int,int> comp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        compress_helper[i]=arr[i];
    }
    sort(all(compress_helper));
    int count=1;
    for(int i=0;i<n;i++){
        if(comp[compress_helper[i]]==0) {
            comp[compress_helper[i]] = count;
            count++;
        }
    }
    //comp[arr[i]] is representent of arr[i]
    SegTree st(n+2);
    set<int> s;
    int answer=0;
    for(int i=n-1;i>=0;i--){
        auto it_high = s.lower_bound(arr[i]+k);
        auto it_low = s.upper_bound(arr[i]-k);
        int res = 0;
        if(it_high != s.end()){
            res = max(res,(int)st.get(comp[*it_high],n).val);
        }
        if(it_low != s.begin()){
            it_low=prev(it_low);
            res = max(res,(int)st.get(1,comp[*it_low]).val);
        }
        s.insert(arr[i]);
        st.upd(comp[arr[i]],max((int)st.get(comp[arr[i]],comp[arr[i]]).val,res+1));
        answer=max(answer,res+1);
    }
    cout<<answer<<endl;

    return 0;
}