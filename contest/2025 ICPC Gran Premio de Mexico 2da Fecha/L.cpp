#include <bits/stdc++.h>

const int maxn = 1e5 + 3;

using namespace std;
const int inf = 1e9;
int arr[maxn];
int tree[4*maxn];
int lazy[4*maxn];
vector<vector<int>> adj;
int n,q,par[maxn],dpth[maxn],sz[maxn],hvyChld[maxn],chHead[maxn],nti[maxn],itn[maxn],cnt;

void calcSz(int u){
    sz[u]=1;
    hvyChld[u]=-1;
    int mx=0, mxChld=-1;
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

void hldDfs(int u,int h){
    chHead[u]=h;
    itn[nti[u]=cnt++]=u;
    if(~hvyChld[u])
        hldDfs(hvyChld[u], h);
    for (auto v: adj[u]) {
        if (v == par[u] || v == hvyChld[u]) continue;
        hldDfs(v, v);
    }
}

void hld(int root){
    dpth[root]=0;
    par[root]=-1;
    cnt=1;
    calcSz(root);
    hldDfs(root, root);
}

void update_tree(int node, int a, int b, int i, int j) {
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] = b-a+1; // Update it
		if(a != b) {
			lazy[node*2] = 1; // Mark child as lazy
    			lazy[node*2+1] = 1; // Mark child as lazy
		}
   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] = b-a+1;
		if(a != b) { // Not leaf node
			lazy[node*2] = 1;
			lazy[node*2+1] = 1;
		}
  		return;
	}
	update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child

	tree[node] = tree[node*2]+ tree[node*2+1]; // Updating root with max value
}
/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] = b-a+1; // Update it

		if(a != b) {
			lazy[node*2] = 1; // Mark child as lazy
			lazy[node*2+1] = 1; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = q1 + q2; // Return final result

	return res;
}

void p(int u, int v) {
	while (chHead[u] != chHead[v]) {
		if (dpth[chHead[u]] < dpth[chHead[v]]) swap(u, v);
		//we take path from
		update_tree(1,1,n,nti[chHead[u]],nti[u]);
		u = par[chHead[u]];
	}
	while (u != v) {
		if (dpth[u] < dpth[v])swap(u,v);
		//we do thing to u
		update_tree(1,1,n,nti[u],nti[u]);
		u = par[u];
	}
	//update_tree(1,1,n,nti[u],nti[u]);
}

int qu(int u, int v) {
	int res = 0;
    while (chHead[u] != chHead[v]) {
        if (dpth[chHead[u]] < dpth[chHead[v]]) swap(u, v);
        //we take path from
    	res += query_tree(1,1,n,nti[chHead[u]],nti[u]);
    	u = par[chHead[u]];
    }
	while (u != v) {
		if (dpth[u] < dpth[v])swap(u,v);
		//we do thing to u
		res += query_tree(1,1,n,nti[u],nti[u]);
		u = par[u];
	}
	//res += query_tree(1,1,n,nti[u],nti[u]);
    return res;
}

int main() {
	cin>>n>>q;
	adj.resize(n+1);
	for (int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	hld(1);

	for (int i=0;i<q;i++) {
		char c;int a,b;
		cin>>c>>a>>b;

		if (c == 'P')
			p(a,b);
		else
			cout<<qu(a,b)<<endl;

	}

    return 0;
}
