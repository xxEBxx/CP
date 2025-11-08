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

extern struct node *const EMPTY;
const int N = 100005;
struct node{
    int sum;
    node *left, *right;
    node():sum(0), left(this), right(this) {}
    node(int s, node *l=EMPTY, node *r=EMPTY): sum(s), left(l),
    right(r) {}
};
node *const EMPTY= new node();
node *insert(int v,node *cur,int ns=0,int ne=1e9){
    if(v>ne || v<ns) return cur;
    if(ns==ne) return new node(cur->sum+1);
    int mid = ns + (ne - ns) / 2;
    node *left = insert(v, cur->left, ns, mid);
    node *right = insert(v, cur->right, mid + 1, ne);
    return new node(cur->sum + 1, left, right);
}
node *roots[N]={EMPTY};
int query(int k,node *se,node *bs, int ns=0, int ne=1e9) {
    if(ns == ne) return ns;
    int leftSum = se->left->sum - bs->left->sum;
    int mid = ns + (ne - ns) / 2;
    if(leftSum >= k)
        return query(k, se->left, bs->left, ns, mid);
    return query(k - leftSum, se->right, bs->right, mid + 1, ne
    );
}


int main() {
    fast();
    int n,q;cin >> n >> q;
    int l[3];cin >> l[1] >> l[2];

    for (int i = 1; i <= n; ++i) {
        int v;cin >> v;
        roots[i] = insert(v, roots[i - 1]);
    }

    while (q--){
        int i,qe,k;cin >> i>> qe >> k;
         cout << query(1, roots[qe+l[i]-1], roots[qe - 1]) << " ";
        cout << query(k, roots[qe+l[i]-1], roots[qe - 1]) << " ";
        cout << query(l[i], roots[qe+l[i]-1], roots[qe - 1]) << endl;

    }

    return 0;
}
