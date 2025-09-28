
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll MAXN = (ll)  1e6 + 7;
const ll mod = (ll) 1e9 + 7;


ii arr[MAXN];                 // initial array (1-indexed)
ii seg[4 * MAXN];             // segment-tree values (range max)
ll lazy[4 * MAXN];            // pending range additions

/* merge: recompute parent value from its two children */
inline void merge(ll node) {
    seg[node] = {seg[node << 1].f+seg[node << 1 | 1].f,seg[node << 1].s+seg[node << 1 | 1].s};
}

/* push: apply and propagate pending lazy value */
inline void push(ll node, ll l, ll r) {
    if (!lazy[node]) return;
    seg[node] = {r-l+1-seg[node].s - seg[node].f,seg[node].s};
    if (l != r) {                         // propagate to children
        lazy[node << 1]     ^= lazy[node];
        lazy[node << 1 | 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

/* build the tree on llerval [l,r] */
void build(ll node, ll l, ll r) {
    if (l == r) { seg[node] = arr[l]; return; }
    ll m = (l + r) >> 1;
    lazy[node]=0;
    build(node << 1,     l, m);
    build(node << 1 | 1, m + 1, r);
    merge(node);
}

/* add val to every element in [ql,qr] */
void update(ll node, ll l, ll r, ll ql, ll qr) {
    push(node, l, r);
    if (r < ql || l > qr) return;         // no overlap
    if (ql <= l && r <= qr) {             // fully covered
        lazy[node] ^= 1;
        push(node, l, r);
        return;
    }
    ll m = (l + r) >> 1;
    update(node << 1,     l, m, ql, qr);
    update(node << 1 | 1, m + 1, r, ql, qr);
    merge(node);
}

/* max query on [ql,qr] */
ll query(ll node, ll l, ll r, ll ql, ll qr) {
    push(node, l, r);
    if (r < ql || l > qr) return 0;    // no overlap
    if (ql <= l && r <= qr) return seg[node].f;
    ll m = (l + r) >> 1;
    return query(node << 1,     l, m, ql, qr)+
               query(node << 1 | 1, m + 1, r, ql, qr);
}


int main() {
    fast();
    ll n,q;
    cin>>n>>q;
    ll res=0;
    for (ll i=1;i<=n;i++) {
        ll a,b;
        cin>>b>>a;
        res += a;
        arr[i]={0,0};
        if (b==1)arr[i].f=1;
        else if (b==-1)arr[i].s=1;
    }

    build(1,1,n);
    for (ll i=0;i<q;i++) {
        char c;cin>>c;
        if (c == 'C') {
            ll a;cin>>a;
            res += query(1,1,n,1,n)*a;
        }
        else {
            ll a,b;
            cin>>a>>b;
            a++;b++;
            update(1,1,n,a,b);
        }
    }

    cout<<res<<endl;
    return 0;
}
