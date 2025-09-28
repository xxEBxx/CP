
#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;

vector<vector<ll>> adj;
ll n,par[N],dpth[N],sz[N],hvyChld[N],chHead[N],nti[N],itn[N],cnt;

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
    cnt=0;
    calcSz(root);
    hldDfs(root, root);
}


const ll maxn  = N;

struct FT {
    vector<ll> s;
    FT(ll n) : s(n,0) {}
    void update(ll pos, ll dif) { // a [ pos ] += d i f
        for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
    }
    ll query(ll pos) { // sum of values in [0 , pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
};

FT ft(maxn);
ll solve(ll u) {
    ll res = 0;
    while (u!=-1) {
        ll head = chHead[u];
        ll headp = par[head];
        ll l = nti[head],r =nti[u];
        res += ft.query(r+1) -  ft.query(l) ;
        u = headp;//going up
    }
    return res;
}

int main() {
    ll q;
    cin>>n>>q;
    vector<ll> value(n);
    for (ll i =0 ;i<n;i++) {
        ll val;cin>>val;
        value[i] = val;
    }

    adj.resize(n+1);
    for(ll u=1;u<n;++u){
        ll a,b;cin>>a>>b;
        a--;b--;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    hld(0);

    for (ll i=0;i<n;i++) {
        ft.update(nti[i],value[i]);
    }

    while (q--){
        ll a;
        cin>>a;
        if (a==2) {
            ll b;cin>>b;b--;
            cout<<solve(b)<<endl;
        }else {
            ll b,x;cin>>b>>x;
            b--;
            ft.update(nti[b],x-value[b]);
            value[b] = x;
        }

    }
    return 0;
}
