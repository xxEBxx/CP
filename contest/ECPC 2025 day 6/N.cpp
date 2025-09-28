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

int main() {
    fast();
    ll n,m,k;
    cin>>n>>m>>k;
    vi arr(n);
    for (ll i=0;i<n;i++)
        cin>>arr[i];
    vvi adj(n,vi(n,0));
    for (ll i=0;i<m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a][b] += c;
        adj[b][a] += c;
    }
    ll res=0;
    for (ll bit=0;bit < (1ll<<n);bit++) {

        if (__builtin_popcountll(bit) != k) continue;
        ll score=0;
        for (ll i=0;i<n;i++) {
            if ((bit>>i &1ll)==0)continue;
            score += arr[i];
            for (ll j=i+1;j<n;j++) {
                if (bit>>j & 1ll)
                    score+=adj[i][j];
            }
        }
        res=max(res,score);
    }
    cout<<res<<endl;
    return 0;
}
