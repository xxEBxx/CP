#include <bits/stdc++.h>
// https://vjudge.net/problem/SPOJ-MKTHNUM
using namespace std;

extern struct node *const EMPTY;
const int N = 100005;
struct node{
    int sum;
    node *left, *right;
    node():sum(0), left(this), right(this) {}
    node(int s, node *l=EMPTY, node *r=EMPTY): sum(s), left(l), right(r) {}
};

node *const EMPTY= new node();
node *insert(int v,node *cur,int ns=-1e9,int ne=1e9){
    if(v>ne || v<ns) return cur;
    if(ns==ne) return new node(cur->sum+1);
    int mid = ns + (ne - ns) / 2;
    node *left = insert(v, cur->left, ns, mid);
    node *right = insert(v, cur->right, mid + 1, ne);
    return new node(cur->sum + 1, left, right);
}

node *roots[N]={EMPTY};

int query(int k,node *se,node *bs, int ns=-1e9, int ne=1e9) {
    if(ns == ne) return ns;
    int leftSum = se->left->sum - bs->left->sum;
    int mid = ns + (ne - ns) / 2;
    if(leftSum >= k)
        return query(k, se->left, bs->left, ns, mid);
    return query(k - leftSum, se->right, bs->right, mid + 1, ne);
}
int main() {
    int n,q;
    scanf("%d%d", &n,&q);
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        roots[i] = insert(v, roots[i - 1]);
    }
    while (q--){
        int qs,qe,k;
        scanf("%d%d%d", &qs, &qe, &k);
        printf("%d\n", query(k, roots[qe], roots[qs - 1]));
    }
    return 0;
}
