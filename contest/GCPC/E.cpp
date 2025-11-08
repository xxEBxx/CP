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
    ll n,x;
    cin>>n>>x;

    vector<ii> arr(n);
    for (ll i=0;i<n;i++)
        cin>>arr[i].f;
    for (ll i=0;i<n;i++)
        cin>>arr[i].s;

    sort(all(arr),[](ii a,ii b) {
        if (a.s!=b.s) return a.s > b.s;
        return a.f<b.f;
    });

    vi prev(n+1,1e18),dp(n+1,1e18);
    prev[0]=0;
    dp[0]=0;
    for (ll i=1;i<=n;i++) {
        //i is for the one that will be taken
        //it means we at most took i-1 element
        //we dont iterate till the end then
        for (ll j=1;j<=i;j++) {
            //j is the iteration
            //j is the state of the dp
            //its how much we take and we use j-1
            dp[j] = min(prev[j],prev[j-1] + arr[i-1].f + arr[i-1].s * (j-1));
        }

        prev = dp;
    }
    for (ll i=n;i>=0;i--) {
        if (x >= dp[i]){
            cout<<i<<" "<<dp[i]<<endl;
            return 0;
        }

    }
}
