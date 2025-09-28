
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
    void add(ll idx,ll v, ll p = 1, ll st = 1, ll en = sz) {
        if (st == en) {
            seg[p].val += v;
            return;
        }
        ll mi = M(st,en);
        if (idx <= mi)
            add(idx,v,L(p), st, mi);
        else
            add(idx,v, R(p), mi + 1, en);
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
//this segment tree in each x we put how much elements have their LSB here

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n,m,q;
        cin >> n>>m>>q;
        vector<string> arr(n);
        vector<set<int>> data(n);
        SegTree st(m+2);
        int cnt_z=0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            int last = -1;
            for (int j=0;j<m;j++) {

                if (arr[i][j]=='1') {
                    data[i].insert(m-1-j);
                    last=m-1-j;
                }

            }
            if (last > -1)
                st.add(last+1,1);
            else
                cnt_z++;
        }

        for (int ii=0;ii<q;ii++) {
            int a;cin>>a;
            if (a==1) {
                int i,j;
                cin>>i>>j;

                if (data[i].count(j) == 1) {
                    if (j == *data[i].begin()) {
                        st.add(j+1,-1);
                        data[i].erase(j);
                        if (!data[i].empty())
                            st.add(1 + *data[i].begin(), 1);
                        else
                            cnt_z++;
                    } else
                        data[i].erase(j);
                }
                else {
                    if (data[i].empty()) {
                        cnt_z--;
                        data[i].insert(j);
                        st.add(j+1, +1);
                    } else {
                        int cur = *data[i].begin();
                        data[i].insert(j);
                        if (j < cur) {
                            st.add(cur+1, -1);
                            st.add(j+1, +1);
                        }
                    }

                }
            } else {
                int x;cin>>x;
                cout<<cnt_z + st.get(x+1,m).val<<endl;
            }
        }

    }
    return 0;
}
