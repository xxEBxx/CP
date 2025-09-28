#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define f first
#define s second
typedef long long ll;
const ll MAXN = 1e5 + 5;
const ll INF  = 1e9;
typedef pair<ll,ll> ii;

ll arr[MAXN];                 // initial array (1-indexed)
pair<ll,ll> seg[4 * MAXN];             // segment-tree values (range max)
ll lazy[4 * MAXN];            // pending range additions

/* merge: recompute parent value from its two children */
inline void merge(ll node) {
    ll c1=node<<1,c2=node<<1|1;
    if (max(seg[c1].f,seg[c1].s) < max(seg[c2].f,seg[c2].s)) {
        seg[node]  = seg[c1];
    }
    else
        seg[node]  = seg[c2];
}

/* push: apply and propagate pending lazy value */
inline void push(ll node, ll l, ll r) {
    if (!lazy[node]) return;
    seg[node].s += lazy[node];
    if (l != r) {                         // propagate to children
        lazy[node << 1]     += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}

/* build the tree on llerval [l,r] */
void build(ll node, ll l, ll r) {
    if (l == r) { seg[node] = {arr[l],0}; return; }
    ll m = (l + r) >> 1;
    build(node << 1,     l, m);
    build(node << 1 | 1, m + 1, r);
    merge(node);
}

/* add val to every element in [ql,qr] */
void update(ll node, ll l, ll r, ll ql, ll qr, ll val) {
    push(node, l, r);
    if (r < ql || l > qr) return;         // no overlap
    if (ql <= l && r <= qr) {             // fully covered
        lazy[node] += val;
        push(node, l, r);
        return;
    }
    ll m = (l + r) >> 1;
    update(node << 1,     l, m, ql, qr, val);
    update(node << 1 | 1, m + 1, r, ql, qr, val);
    merge(node);
}

/* max query on [ql,qr] */
ii query(ll node, ll l, ll r, ll ql, ll qr) {
    push(node, l, r);
    if (r < ql || l > qr) return {INF,INF}; // no overlap
    if (ql <= l && r <= qr) return seg[node];
    ll m = (l + r) >> 1;
    ii c1 =query(node << 1,     l, m, ql, qr);
    ii c2 =query(node << 1 | 1, m + 1, r, ql, qr);

    if (max(c1.f,c1.s) < max(c2.f,c2.s)) {
        return c1;
    }
    else
        return c2;
}

int main() {
    ll n,q;
    cin>>n>>q;
    for (ll i=1;i<=n;i++){cin>>arr[i];}
    build(1,1,n);
    for (ll i=0;i<q;i++) {
        ll x;
        cin>>x;
        if (x==1) {
            ll a,b,c;
            cin>>a>>b>>c;
            update(1,1,n,a,b,c);
        }
        else {
            ll a,b;
            cin>>a>>b;
            ii res = query(1,1,n,a,b);
            cout<<max(res.f,res.s)<<endl;
        }
    }
}