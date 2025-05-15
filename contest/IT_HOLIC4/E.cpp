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
           val = 0;
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
       res.val = max(L.val,R.val);
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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n),ans_first(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int counter=1;
        map<int,int> compress,reverse_compress;
        vi sorted=arr;
        sort(all(sorted));
        for(int i=0;i<n;i++){
            if(compress[sorted[i]]==0){
                compress[sorted[i]]=counter;
                reverse_compress[counter]=sorted[i];
                counter++;
            }
        }

        for(int i=0;i<n;i++){
            arr[i] = compress[arr[i]];
            //cout<<arr[i]<<" ";
        }

        SegTree st(n);
        int max_far=0;
        for(int i=0;i<n;i++){
            max_far=max(max_far,arr[i]);
            ans_first[i]=max_far;
            st.upd(arr[i],max_far);
        }


        vi ans(n);
        for(int i=n-1;i>=0;i--){
            if(arr[i] == 1)
                ans[i]=ans_first[i];
            else {
                //cout<<"going from 1 to "<<arr[i]-1<<"and found "<<(int) st.get(1, arr[i] - 1).val<<endl;
                ans[i] = max(ans_first[i], (int) st.get(1, arr[i] - 1).val);
            }

            st.upd(arr[i],ans[i]);
        }
        for(auto elem:ans)
            cout<<reverse_compress[elem]<<" ";
        cout<<endl;
    }
    return 0;
}