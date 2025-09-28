#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 1e6 + 5;
const ll INF  = 1e9;

ll seg[4 * MAXN];             // segment-tree values (range max)
ll lazy[4 * MAXN];            // pending range additions

/* merge: recompute parent value from its two children */
inline void merge(ll node) {
    seg[node] = max(seg[node << 1], seg[node << 1 | 1]);
}

/* push: apply and propagate pending lazy value */
inline void push(ll node, ll l, ll r) {
    if (lazy[node] == -1) return;
    seg[node] = lazy[node];
    if (l != r) {                         // propagate to children
        lazy[node << 1]     = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = -1;
}

/* build the tree on llerval [l,r] */
void build(ll node, ll l, ll r) {
    lazy[node] = -1;
    if (l == r) { seg[node] = 0; return; }
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
        lazy[node] = val;
        push(node, l, r);
        return;
    }
    ll m = (l + r) >> 1;
    update(node << 1,     l, m, ql, qr, val);
    update(node << 1 | 1, m + 1, r, ql, qr, val);
    merge(node);
}

/* max query on [ql,qr] */
ll query(ll node, ll l, ll r, ll ql, ll qr) {
    push(node, l, r);
    if (r < ql || l > qr) return -INF;    // no overlap
    if (ql <= l && r <= qr) return seg[node];
    ll m = (l + r) >> 1;
    return max(query(node << 1,     l, m, ql, qr),
               query(node << 1 | 1, m + 1, r, ql, qr));
}

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}


int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<ll> a;
        for (int i=0;i<n-1;i++) {
            if (arr[i]==arr[i+1])continue;
            a.push_back(arr[i]);
        }
        a.push_back(arr[n-1]);
        arr = a;
        n=arr.size();
        build(1,0,n+2);


        ll res = 0;
        for (ll i=0;i<n;i++) {
            ll need = query(1,0,n,arr[i],arr[i]);
            if (need > 0 || arr[i]==0) {
                res += n-i;
                update(1,0,n,arr[i]+1,arr[i]+1,1);
            }
            update(1,0,n,0,arr[i],0);
        }
        cout<<res<<endl;
    }
    return 0;
}
