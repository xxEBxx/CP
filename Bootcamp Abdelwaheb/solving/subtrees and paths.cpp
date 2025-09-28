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

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of =in f
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};
const int N = maxn;
vector<vector<ll>> adj;
ll n,par[N],dpth[N],sz[N],hvyChld[N],chHead[N],tin[N],itn[N],cnt;

void calcSz(ll u){
    sz[u]=1;
    hvyChld[u]=-1;
    ll mx=0, mxChld=-1;
    for (auto v: adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dpth[v] = dpth[u] + 1;
        calcSz(v);
        sz[u] += sz[v];
        if(sz[v] > mx) {
            mx = sz[v];
            mxChld = v;
        }
    }
    if(mx*2>= sz[u])
        hvyChld[u] = mxChld;
}

void hldDfs(ll u,ll h){
    chHead[u]=h;
    itn[tin[u]=cnt++]=u;
    if(~hvyChld[u])
        hldDfs(hvyChld[u], h);
    for (auto v: adj[u]) {
        if (v == par[u] || v == hvyChld[u]) continue;
        hldDfs(v, v);
    }
    //itn[tout[u]=cnt++]=u;

}
void hld(ll root){
    dpth[root]=0;
    par[root]=-1;
    cnt=0;
    calcSz(root);
    hldDfs(root, root);
}

Node st(0,N+1);

int solve(int a,int b) {
    int ans = -1e9;
    while ( chHead[a] != chHead[b] ) {
        //we increase both by chhead
        if (dpth[chHead[a]] < dpth[chHead[b]] ) { // we make a the deepest
            swap(a,b);
        }

        ans = max(ans,st.query(tin[chHead[a]],tin[a]+1));
        a = par[chHead[a]];
    }

    if (dpth[a] < dpth[b] )  // we make a the deepest
        swap(a,b);

    ans = max(ans,st.query(min(tin[a],tin[b]),1+max(tin[a],tin[b])));

    return ans;
}

int main() {
    fast();
    st.add(0,N+1,1e9);
    int n;cin>>n;
    adj.resize(n+1);
    for (int i=1;i<n;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    hld(0);


    int q;cin>>q;
    while (q--) {
        string s;int a,b;
        cin>>s>>a>>b;

        if (s[0]=='a') {
            a--;
            st.add(tin[a],tin[a] + sz[a],b);
            //cout<<st.query(0,N)<<endl;
        }
        else {
            a--;b--;
            cout<<solve(a,b)<<endl;
        }
    }
    return 0;
}
