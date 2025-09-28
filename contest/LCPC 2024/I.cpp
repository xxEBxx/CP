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

const ll maxn = (ll) 1e5 + 7;
const ll mod = (ll) 1e9 + 7;


vector<ii> tree;
vi arr,lazy;
const ll inf = 1e18;
/**
 * Build and init tree
 */
void build_tree(ll node, ll a, ll b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = {arr[a],a}; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	if (tree[node*2].f > tree[node*2+1].f)
		tree[node] = tree[node*2]; // Init root value
	else
		tree[node] = tree[node*2+1]; // Init root value

}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {
	if(lazy[node] != 0) { // This node needs to be updated
		tree[node].f += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

	if(a >= i && b <= j) { // Segment is fully within range
		tree[node].f += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	if (tree[node*2].f > tree[node*2+1].f)
		tree[node] = tree[node*2];
	else
		tree[node] = tree[node*2+1];
}

ii query_tree(ll node, ll a, ll b, ll i, ll j) {

	if(a > b || a > j || b < i) return {-inf,-inf}; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node].f += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ii q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	ii q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	if (q1.f>q2.f)
		return q1;
	return q2;
}

int main(){
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
    	arr.assign(n, 0);
    	lazy.assign(4*n, 0);
    	tree.assign(4*n, {0,0});

    	for (ll i=0;i<n;i++) {
    		cin>>arr[i];
    	}
    	build_tree(1,0,n-1);
    	for (ll i=0;i<n;i++) {
    		ii res = query_tree(1,0,n-1,0,n-1);
    		update_tree(1,0,n-1,res.s,res.s,-inf);
    		update_tree(1,0,n-1,res.s,n-1,-1);
    		cout<<res.f<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}
