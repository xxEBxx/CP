#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 1e6 + 7;
const int mod = (int) 1e9 + 7;
vi spf(maxn,-1);
void estratos() {
    for (int i=2;i<maxn;i++) {
        if (spf[i] == -1) {
            //i is prime
            for (int j=i;j<maxn;j+=i) {
                spf[j]=i;
            }
        }
    }
}
vi decompose(int x) {
    vi res;
    while (x>1) {
        int d =spf[x];
        while (x%d==0)
            x/=d;
        res.push_back(d);
    }
    return res;
}
struct node {
    int f,s,i;
};
bool comp(node a,node b) {
    return a.s<b.s;
}

#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;
class SegTree {
    struct Node {
        ll val;
        Node() {
            val = 1e9;//you can make it an array here or 2 values or a small array...
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
        res.val = min(L.val , R.val);
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
    fast();
    estratos();
    int n,q,k;
    cin>>n>>q>>k;
    vi arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }

    vi r(n,-1);//if we start at i where will we finish

    unordered_map<int,int> count;//each prime repeated how many times
    int s=0,e=0,good=0;
    vi d = decompose(arr[e]);
    for (auto elem : d) {
        count[elem]++;
        if (count[elem] == k)good++;
    }

    while (e<n) {
        if (good > 0) {
            r[s]=e;
            vi d = decompose(arr[s]);
            for (auto elem : d) {
                count[elem]--;
                if (count[elem] == k-1)good--;
            }
            s++;
        }
        else {
            e++;
            if (e==n)break;
            vi d = decompose(arr[e]);
            for (auto elem: d) {
                count[elem]++;
                if (count[elem] == k)good++;
            }
        }
    }

    vector<node> query(q);

    for (int i=0;i<q;i++) {
        cin>>query[i].f>>query[i].s;
        query[i].i=i;
    }
    sort(all(query),comp);
    unordered_map<int,vi> reverse_r;
    for (int i=0;i<n;i++) {
        reverse_r[r[i]].push_back(i);
    }
    int curr_r=-1;
    SegTree st(n+1);
    vi ans(q);
    for (int i=0;i<q;i++) {
        while (curr_r < query[i].s-1) {
            curr_r++;
            //activate it in segemtn tree
            for (int j : reverse_r[curr_r]) {
                st.upd(j+1, r[j] - j + 1);
            }
        }
        int res = st.get(query[i].f,query[i].s).val;
        ans[query[i].i] = res;
    }
    for (auto elem : ans){
        if (elem==1e9)
            cout<<-1<<endl;
        else cout<<elem<<endl;
    }
    return 0;
}
