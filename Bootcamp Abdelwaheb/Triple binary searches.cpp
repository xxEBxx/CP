#include <bits/stdc++.h>
//https://vjudge.net/problem/SPOJ-MKTHNUM
using namespace std;

const int N=1<<18;
vector<int> seg[N];
int arr[N],n;

void build(int ni=0,int ns=0,int ne=n-1){
    if(ns==ne){
        seg[ni].push_back(arr[ns]);
        return;
    }
    int l=2*ni+1,r=l+1,m=ns+(ne-ns)/2;
    build(l,ns,m);
    build(r,m+1,ne);
    merge(seg[l].begin(), seg[l].end(),
          seg[r].begin(), seg[r].end(),
          back_inserter(seg[ni]));
}

int query(int x,int qs,int qe,int ni=0,int ns=0,int ne=n-1) {
    if (qs > ne || qe < ns) return 0; // no overlap
    if (qs <= ns && qe >= ne) { // total overlap
        return upper_bound(seg[ni].begin(), seg[ni].end(), x) - seg[ni].begin();
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    return query(x, qs, qe, l, ns, m) + query(x, qs, qe, r, m + 1, ne);
}

int main() {
    int q;
    scanf("%d%d", &n,&q);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    build();
    while (q--){
        int qs,qe,k;
        scanf("%d%d%d", &qs, &qe, &k);
        qs--, qe--;

        int s=mn-1, e=mx+1;

        while(s+1<e){
            int m = s + (e - s) / 2;
            if (query(m, qs, qe) >= k) {
                e = m; // m is a valid answer
            } else {
                s = m; // m is not a valid answer
            }
        }
        printf("%d\n", e);
    }
    return 0;
}
