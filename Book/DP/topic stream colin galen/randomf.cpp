#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll dp[maxn][maxn],n,m;
ll solve(ll i,ll j){
    if(i==n || j==m) {
        if (i == n && j == m)
            return 0;
        return (ll) -1e18;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll res=solve(i+1,j);
    res=max(res,solve(i+1,j+1));
    return dp[i][j]=res
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    return 0;
}