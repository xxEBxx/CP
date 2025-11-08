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

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

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
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n>>q;
        vi arr(n+1);
        SegTree st(n+2);
        vi ps0(n+1,0),ps1(n+1,0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            ps0[i]=ps0[i-1];
            ps1[i]=ps1[i-1];
            if (arr[i]==0)
                ps0[i]++;
            else
                ps1[i]++;
        }
        for (int i=2;i<=n;i++) {
            if (arr[i] == arr[i-1]) {
                st.upd(i,1);
                st.upd(i-1,1);
            }
        }

        for (int i =0;i<q;i++) {
            int a,b;
            cin>>a>>b;
            if ((b-a+1)%3 != 0
                || (ps0[b]-ps0[a-1])%3 != 0
                || (ps1[b]-ps1[a-1])%3 != 0) {
                cout<<-1<<endl;
                continue;
            }
            int res = (b-a+1) / 3 + 1;
            if (st.get(a+1,b-1).val > 0) {
                res--;
            }
            cout<<res<<endl;
        }



    }
    return 0;
}
