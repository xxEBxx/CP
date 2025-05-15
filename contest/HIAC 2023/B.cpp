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

const int maxn=(int)2*1e6;
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
struct comp{
    bool operator()(pair<int,int> a,pair<int,int> b)const{
        if(a.f!=b.f)return a.f<b.f;
        return a.s>b.s;
    }
};


int main(){
    vector<int> divisors(maxn,1);
    for(int i=2;i<maxn;i++){
        for(int mult=i;mult<maxn;mult+=i){
            if(divisors[i] == i || divisors[i] == 1)
                divisors[mult] = max(divisors[mult],i);
        }
    }
    //for(int i=1;i<30;i++)cout<<divisors[i]<<" ";cout<<endl;
    int n,q;
    scanf("%d %d",&n,&q);
    //cin>>n>>q;
    SegTree st(maxn);

    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> arr;
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        if(val != 1){
            arr.emplace(make_pair(val,i+1));
        }
    }
    int count = 0;

    while(!arr.empty()){
        count += 1;
        pair<int,int> m = arr.top();
        arr.pop();
        pair<int,int> t ;
        if(divisors[m.first] == 1){
            t = {1,m.second};
        }
        else{
            t = {m.first/((divisors[m.first])),m.second};
        }

        if(t.first == 1){
            st.upd(t.second,count);
        }else{
            arr.push(t);
        }
    }

    for(int i=0,a,b;i<q;i++){
        scanf("%d %d",&a,&b);
        ll res=st.get(a,b).val;
        printf("%l\n",&res);
    }


    return 0;
}