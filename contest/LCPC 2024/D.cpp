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


#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vi arr,tree,lazy;

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] = max(tree[node],lazy[node]); // Update it
		if(a != b) {
			lazy[node*2] = max(lazy[node*2] ,lazy[node]); // Mark child as lazy
    			lazy[node*2+1] = max(lazy[node*2+1] ,lazy[node]); // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] = max(tree[node],value);

		if(a != b) { // Not leaf node
			lazy[node*2] = max(lazy[node*2],value);
			lazy[node*2+1] = max(lazy[node*2+1],value);
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] = max(tree[node],lazy[node]); // Update it

		if(a != b) {
			lazy[node*2] = max(lazy[node*2],lazy[node]); // Mark child as lazy
			lazy[node*2+1] = max(lazy[node*2+1],lazy[node]); // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}
void init(int n) {
	arr.resize(n+1);
	lazy.assign(4*(n+1),0);
	tree.assign(4*(n+1),0);
}

int main() {
	fast();
	int t;cin>>t;
	while (t--) {
		int n;cin>>n;
		init(n);
		for (int i=1;i<n+1;i++)
			cin>>arr[i];
		//build_tree(1,1,n);
		//st stores best answer for a lentgh
		vector<ii> v;//v stores gcd,start
		for (int r=1;r<=n;r++) {
			vector<ii> nv;
			nv.push_back({arr[r],r});

			for (auto elem : v) {
				int ng = gcd(arr[r],elem.f);
				//if it was seen before we dont add it
				if (ng == nv.back().f )
					nv.back().s = min(nv.back().s,elem.s);
				else
					nv.push_back({ng, elem.s});
			}

			for (int i = 0; i < nv.size(); ++i) {
				int s = nv[i].s;      // earliest start of this step
				int g = nv[i].f;

				int prevStart = (i == 0) ? r + 1 : nv[i - 1].s;
				int e = prevStart - 1;                 // latest start in this step

				int len_min = r - e + 1;               // shortest block in step
				int len_max = r - s + 1;               // longest  block in step

				update_tree(1, 1, n, len_min, len_max, g);
			}


			v = nv;
		}
		int q;cin>>q;
		while (q--) {
			int val;cin>>val;
			cout<<query_tree(1,1,n,val,val)<<endl;
		}

	}

	return 0;
}