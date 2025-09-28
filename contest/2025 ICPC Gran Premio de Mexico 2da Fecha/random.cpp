
#include <bits/stdc++.h>


using namespace std;
typedef long long ll ;
const ll N = 1e5 + 2;

vector<vector<ll>> adj;
ll n,par[N],base[N],dpth[N],sz[N],hvyChld[N],chHead[N],nti[N],itn[N],cnt;

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
    itn[nti[u]=cnt++]=u;
    if(~hvyChld[u])
        hldDfs(hvyChld[u], h);
    for (auto v: adj[u]) {
        if (v == par[u] || v == hvyChld[u]) continue;
        hldDfs(v, v);
    }

}
void hld(ll root){
    dpth[root]=0;
    par[root]=-1;
    cnt=1;
    calcSz(root);
    hldDfs(root, root);
}

struct node {
	ll pre,suff,sum,tot;
};
ll arr[N];
node tree[4*N];
ll lazy[4*N];

/**
 * Build and init tree
*/
node merge(node a,node b) {
	node res ;
	res.tot = a.tot+b.tot;
	res.pre = max(a.pre,a.tot+b.pre);
	res.suff = max(b.suff,b.tot+a.suff);
	res.sum = max(max(a.sum,b.sum),a.suff+b.pre);
	return res;
}

void build_tree(ll node, ll a, ll b) {
  	if(a > b) return; // Out of range

	if (a == b) {
		ll best = max(0ll, base[a]);
		tree[node] = {best,best,best,base[a]};   // FIX
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = merge(tree[2*node],tree[2*node+1]); // Init root value
}
/**
 * Increment elements within range [i, j] with value value
 */
const ll inf =1e9;
void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {

  	if(lazy[node] != inf) { // This node needs to be updated

  		long long seg = 1LL*(b-a+1)*lazy[node];      // FIX
  		ll best = seg > 0 ? ll(seg) : 0;           // FIX
  		tree[node] = {best,best,best,ll(seg)};

		if(a != b) {
			lazy[node*2] = lazy[node]; // Mark child as lazy
    			lazy[node*2+1] = lazy[node]; // Mark child as lazy
		}

   		lazy[node] = inf; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

	if(a >= i && b <= j){                // segment fully in range
		long long seg = 1LL*(b-a+1)*value;       // <- NEW
		ll best = seg > 0 ? ll(seg) : 0;       // <- NEW
		tree[node] = {best,best,best,ll(seg)};  // <- FIX, now 4 fields

		if(a != b){
			lazy[node*2]   = value;
			lazy[node*2+1] = value;
		}
		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = merge(tree[node*2], tree[node*2+1]); // Updating root with max value
}

node query_tree(ll node, ll a, ll b, ll i, ll j) {

	if(a > b || a > j || b < i) return {0,0,0,0}; // Out of range

	if(lazy[node] != inf) { // This node needs to be updated
		long long seg = 1LL*(b-a+1)*lazy[node];      // FIX
		ll best = seg > 0 ? ll(seg) : 0;           // FIX
		tree[node] = {best,best,best,ll(seg)};

		if(a != b) {
			lazy[node*2] = lazy[node]; // Mark child as lazy
			lazy[node*2+1] = lazy[node]; // Mark child as lazy
		}

		lazy[node] = inf; // Reset it
	}

	if(a >= i && b <= j)
		return tree[node];

	return merge(query_tree(node*2, a, (a+b)/2, i, j), query_tree(1+node*2, 1+(a+b)/2, b, i, j)); // Return final result
}

void update(ll u, ll v,ll c) {
	while (chHead[u] != chHead[v]) {
		if (dpth[chHead[u]] < dpth[chHead[v]]) swap(u, v);
		update_tree(1,1,n,nti[chHead[u]],nti[u],c);
		u = par[chHead[u]];
	}
	while (u != v) {
		if (dpth[u] < dpth[v]) swap(u, v);
		update_tree(1,1,n,nti[u],nti[u],c);
		u = par[u];
	}
	update_tree(1,1,n,nti[u],nti[u],c);
}

ll query(ll u, ll v)
{
	node left  = {0,0,0,0};   // path prefix from u up to (but not incl.) LCA
	node right = {0,0,0,0};   // path suffix from v   ……………………………… LCA

	while (chHead[u] != chHead[v]){
		if (dpth[chHead[u]] >= dpth[chHead[v]]){   /* climb on u-side (going *up*) → segment direction must be flipped */
			node cur = query_tree(1, 1, n, nti[chHead[u]], nti[u]);
			swap(cur.pre, cur.suff);          // reverse the segment
			left = merge(cur, left);           // prepend to prefix
			u = par[chHead[u]];
		}
		else{   /* climb on v-side (going *up* on v) but that segment is *downward*
			   in final path order, so keep its direction and prepend            */
			node cur = query_tree(1, 1, n, nti[chHead[v]], nti[v]);
			right = merge(cur, right);         // prepend to suffix
			v = par[chHead[v]];
		}
	}

	/* u and v now on the same chain:  v is the higher (or equal) node  */
	if (dpth[u] < dpth[v]) swap(u, v);         // ensure u is deeper
	node mid = query_tree(1, 1, n, nti[v], nti[u]);   // [v … u] along base array
	swap(mid.pre, mid.suff);                   // reverse, because we go up
	left = merge(mid, left);                   // prepend the middle part

	/* right already has correct order (top → bottom), no extra flip needed */

	return merge(left, right).sum;             // ≥ 0   (empty path allowed)
}



int main() {
    cin>>n;
	adj.resize(n+1);
	for (ll & i : lazy)i=1e9;
	for (ll i=1;i<=n;i++)
		cin>>arr[i];

	for (ll i=1;i<n;i++) {
		ll a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	hld(1);
	for (ll v = 1; v <= n; ++v) base[nti[v]] = arr[v];

	build_tree(1,1,n);

	ll q;cin>>q;
	while (q--) {
		ll a;cin>>a;
		if (a==1) {
			ll x,y;cin>>x>>y;
			cout<<max(0ll,query(x,y))<<endl;
		}
		else {
			ll x,y,z;
			cin>>x>>y>>z;
			update(x,y,z);
		}
	}


    return 0;
}
