#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(v) v.begin(), v.end()
#define L(i) ((i)<<1)
#define R(i) (((i)<<1)|1)
#define M(i,j) (((i)+(j))>>1)

void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

// ---- segment tree kept (sum of values + count) over compressed ranks ----
ll sz;
class SegTree {
public:
    struct Node { ll val, occ; Node(): val(0), occ(0) {} };
    vector<Node> seg;
    SegTree(ll n){ sz = n; seg.assign(4*n, Node()); }
    static Node merge(const Node &A, const Node &B){
        Node C; C.val=A.val+B.val; C.occ=A.occ+B.occ; return C;
    }
    void upd(ll idx, ll v, ll add, ll p=1, ll st=1, ll en=sz){
        if(st==en){
            if(add==1){ seg[p].val+=v; seg[p].occ++; }
            else      { seg[p].val-=v; seg[p].occ--; }
            return;
        }
        ll mi=M(st,en);
        if(idx<=mi) upd(idx,v,add,L(p),st,mi);
        else        upd(idx,v,add,R(p),mi+1,en);
        seg[p]=merge(seg[L(p)],seg[R(p)]);
    }
    Node get(ll l, ll r, ll p=1, ll st=1, ll en=sz){
        if(l>r) return Node();                    // *** guard
        if(l<=st && en<=r) return seg[p];
        if(r<st || en<l) return Node();
        ll mi=M(st,en);
        Node A=get(l,r,L(p),st,mi), B=get(l,r,R(p),mi+1,en);
        return merge(A,B);
    }
};

// ---- problem code ----
struct Query{ int l,r,i; long long k; };          // *** k -> ll

// Mo’s block size (can keep constant; fine for correctness)
const int BASE = 447; // ~sqrt(2e5)

static inline bool mo_cmp(const Query &a, const Query &b){
    int ba=a.l/BASE, bb=b.l/BASE;
    if(ba!=bb) return ba<bb;
    return (ba&1) ? (a.r>b.r) : (a.r<b.r);
}

int main(){
    fast();

    int n,q;
    if(!(cin>>n>>q)) return 0;
    vector<int> A(n);
    int maxA=0;
    for(int i=0;i<n;i++){ cin>>A[i]; maxA=max(maxA,A[i]); }

    // sieve up to maxA
    vector<char> isPrime(maxA+1,true);
    if(maxA>=0) isPrime[0]=false;
    if(maxA>=1) isPrime[1]=false;
    for(long long p=2;p*(long long)p<=maxA;++p)
        if(isPrime[p])
            for(long long j=p*p;j<=maxA;j+=p) isPrime[(int)j]=false;

    // prev prime <= x
    vector<int> prevP(maxA+1,0);
    int last=0;
    for(int x=2;x<=maxA;x++){ if(isPrime[x]) last=x; prevP[x]=last; }

    // price per element (INF for a[i]==1 => unreachable)
    const int INF_PRICE = -1;                       // *** mark unreachable
    vector<int> price(n);
    vector<char> ok(n, false);                      // *** only ok[i] get into data structure
    for(int i=0;i<n;i++){
        if(A[i] >= 2 && prevP[A[i]]>0){
            price[i] = A[i] - prevP[A[i]];          // 0 if already prime
            ok[i] = true;
        }else{
            price[i] = INF_PRICE;                   // unreachable
            ok[i] = false;
        }
    }

    // coordinate compression over reachable prices only
    vector<int> vals;
    vals.reserve(n);
    for(int i=0;i<n;i++) if(ok[i]) vals.push_back(price[i]);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int U = (int)vals.size();
    if(U==0){
        // nothing reachable anywhere; all answers are 0
        while(q--){ int l,r; long long k; cin>>l>>r>>k; cout<<0<<"\n"; }
        return 0;
    }
    auto rankOf = [&](int v)->int {                  // 1-based rank
        return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin()) + 1;
    };
    auto prefixRank = [&](int thr)->int {            // # distinct values <= thr
        return int(upper_bound(vals.begin(), vals.end(), thr) - vals.begin()); // in [0..U]
    };

    // compressed rank per position (undefined if !ok[i], but we won’t use it)
    vector<int> ridx(n, -1);
    for(int i=0;i<n;i++) if(ok[i]) ridx[i] = rankOf(price[i]);

    vector<Query> qs(q);
    for(int i=0;i<q;i++){
        int l,r; long long k;
        cin>>l>>r>>k;
        --l; --r;                                   // *** convert to 0-based
        qs[i] = {l,r,i,k};
    }
    sort(qs.begin(), qs.end(), mo_cmp);

    SegTree st(U);                                  // *** segtree over ranks [1..U]

    auto add = [&](int idx){
        if(!ok[idx]) return;                        // *** skip unreachable a[idx]==1
        st.upd(ridx[idx], price[idx], 1);
    };
    auto removeOne = [&](int idx){
        if(!ok[idx]) return;                        // *** skip unreachable
        st.upd(ridx[idx], price[idx], 0);
    };

    auto prefixNode = [&](int value)->SegTree::Node {
        int r = prefixRank(value);                  // r in [0..U]
        if(r==0) return SegTree::Node();
        return st.get(1, r);                        // sum/count of costs <= value
    };

    vector<long long> ans(q,0);
    int curL=0, curR=-1;

    // initialize empty window; no pre-add (avoids corner bug when l>0)
    for(const auto &qu : qs){
        while(curR < qu.r) add(++curR);
        while(curR > qu.r) removeOne(curR--);
        while(curL < qu.l) removeOne(curL++);
        while(curL > qu.l) add(--curL);

        // binary search on cost threshold (value-space) as you wanted
        int mn = 0, mx = 10000000, mid;
        SegTree::Node res;
        while(mn + 1 < mx){
            mid = mn + (mx - mn)/2;
            res = prefixNode(mid);
            if(res.val > qu.k) mx = mid - 1;
            else               mn = mid;
        }
        int best;
        SegTree::Node resMx = prefixNode(mx);
        best = (resMx.val <= qu.k) ? mx : mn;

        SegTree::Node pref = prefixNode(best);
        long long taken = pref.occ;
        long long rest  = qu.k - pref.val;

        // try to take from the next distinct price only (optimal)
        int r = prefixRank(best);
        if(r < U && rest > 0){
            int nextRank = r + 1;
            int nextVal  = vals[nextRank - 1];      // actual next price (>best), guaranteed > 0
            // count available at nextRank
            auto leaf = st.get(nextRank, nextRank);
            long long avail = leaf.occ;
            if(nextVal > 0 && avail > 0){
                long long can = min(avail, rest / (long long)nextVal);
                taken += can;
            }
        }
        ans[qu.i] = taken;
    }

    for(long long v: ans) cout << v << "\n";
    return 0;
}
