
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

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

vvi g;
vi sz;

ll dfs(ll i,ll p) {
    ll res=1;
    for (ll c : g[i]) {
        if (c==p)continue;
        res += dfs(c,i);
    }
    return sz[i] = res;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        g.assign(n+1,{});
        sz.resize(n+1);
        vector<ii> e;
        for (ll i=0;i<n-1;i++) {
            ll a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
            e.push_back({a,b});
        }

        ll m ;
        cin>>m;
        vi s(m);
        for (ll i=0;i<m;i++) {
            cin>>s[i];
        }
        sort(all(s));
        vi p;
        if (s.size() < n-1) {
            for (int i=0;i<n-1-s.size();i++)p.push_back(1);
            for (auto elem : s)p.push_back(elem);
        }
        else {
            p.assign(n-1,1);
            for (int i=0;i<n-2;i++) {
                p[i] =s[i];
            }
            p[n-2] = s[n-2];
            for (ll i=n-1;i<m;i++) {
                p[n-2] *= s[i];
                p[n-2]%=mod;
            }
        }

        for (ll i:s)
            p.push_back(i);

        dfs(1,1);
        vi occ(n-1);
        for (ll i=0;i<n-1;i++) {
            ll par=e[i].f,child=e[i].s;
            if (sz[par] < sz[child])
                swap(par,child);
            occ[i] = sz[child]*(n-sz[child]);
            //occ[i] %= mod;
        }
        sort(all(occ));
        ll res=0;
        for (ll i=0;i<n-1;i++) {
            res += (occ[i]%mod)*p[i];
            res %= mod;
        }
        cout<<res<<endl;
    }
    return 0;
}
