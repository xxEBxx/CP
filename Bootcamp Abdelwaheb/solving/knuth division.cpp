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

const ll maxn = (ll) 5001;
const ll mod = (ll) 1e9 + 7;

ll arr[maxn],ps[maxn],opt[maxn][maxn],dp[maxn][maxn],n;
ll solve() {

    for (ll i=1;i<=n;i++) {
        dp[1][i] = 0;//it is of lentgh 1
        opt[1][i] = i;
    }

    for (ll len = 2 ;len <= n;len++) {
        for (ll i=1 ; i+len-1 <= n;i++) {
            ll s=i , e = i + len - 1;
            for (ll j = opt[len-1][i] ; j <= min(opt[len-1][i+1],e-1) ;j++) {
                ll loc = dp[j-s+1][s] + dp[e-j][j+1] + ps[e]-ps[s-1];
                if (loc < dp[len][i]) {
                    dp[len][i] = loc;
                    opt[len][i] = j;
                }
            }
        }
    }
    return dp[n][1];
}

int main() {
    fast();
    memset(dp,0x3F,sizeof(dp));
    ps[0] = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        ps[i] = ps[i-1] + arr[i];
    }
    cout<<solve()<<endl;


    return 0;
}
