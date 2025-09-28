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

const ll maxn = 21;
const ll mod = (ll) 1e9 + 7;

ll arr[maxn],n,d[maxn],par[maxn];
vvi g(maxn);
void dfs(ll i,ll p) {
    d[i] = d[p]+1;
    par[i] = p;
    for (auto c:g[i]) {
        if (p==c)continue;
        dfs(c,i);
    }
}

ll lca(ll a,ll b,ll mask) {
    if (d[a] < d[b])swap(a,b);
    //a is deeper
    while (d[a]>d[b])
        a=par[a];
    while (a!=b && d[a] == d[b]) {
        a = par[a];
        b = par[b];
    }
    while ((mask>>a) &1) {//this node was destroyed
        a = par[a];
    }
    return arr[a];
}
ll dp[(1<<maxn)+2];
ll solve(ll mask) {
    if ((mask == (1<<n)-1) || (mask == (1<<n)-2))//didnt take the 0th
        return 0;
    if (dp[mask] != -1)
        return dp[mask];

    //we chose 2 empty
    ll res=1e18;
    int start=1;
    if (n%2==0 && __builtin_popcount(mask)==(n-2))
        start=0;
    for (ll i = start;i<n;i++) {
        if (mask>>i & 1)continue;
        for (ll j=i+1;j<n;j++) {
            if (mask>>j & 1)continue;
            res = min(res,lca(i,j,mask) + solve(mask | (1<<j) | (1<<i)));
        }
    }
    return dp[mask] = res;
}

int main() {
    fast();
    cin>>n;
    for (ll i=0;i<n;i++)
        cin>>arr[i];
    for (ll i=1;i<n;i++) {
        ll a,b;
        cin>>a>>b;a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    par[0]=-1;
    d[0]=0;
    dfs(0,0);

    memset(dp,-1,sizeof(dp));

    cout<<solve(0)<<endl;
    return 0;
}
