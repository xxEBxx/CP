

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

const ll maxn = 5002 ;
const ll mod = (ll) 1e9 + 7;
vvi child(maxn);
vi price(maxn),discount(maxn);


vi dp[maxn][2];
//for this subtree there is a list that maps i -> best price to take
// i elements

vi merge(vi a,vi b) {
    vi res(a.size()+b.size()-1,1e18);
    for (ll i=0 ; i<a.size();i++) {
        for (ll j=0 ; j<b.size();j++) {
            res[i+j] = min(a[i]+b[j],res[i+j]);
        }
    }
    return res;
}

void dfs(ll i) {

    dp[i][0].push_back(0);
    dp[i][0].push_back(price[i]);

    dp[i][1].push_back(1e18);
    dp[i][1].push_back(discount[i]);

    for (ll c : child[i]) {
        dfs(c);
        dp[i][0] = merge(dp[i][0],dp[c][0]);
        dp[i][1] = merge(dp[i][1],dp[c][1]);
    }
    for (ll ii=0;ii<dp[i][0].size();ii++) {
        dp[i][1][ii] = min(dp[i][1][ii],dp[i][0][ii]);
    }
}

int main() {
    fast();
    ll n,b;
    cin >> n>>b;
    vi arr(n);
    for (ll i = 1; i <= n; i++) {
        cin>>price[i]>>discount[i];
        discount[i]  = price[i]-discount[i];
        if (i>1) {
            ll p;cin>>p;
            child[p].push_back(i);
        }
    }
    dfs(1);
    for (ll i=n;i>=0;i--) {
        if (dp[1][1][i] <= b) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
