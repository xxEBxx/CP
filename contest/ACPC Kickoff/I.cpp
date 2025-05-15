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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

int main(){fast();

    vector<ll> dp(maxn,0);
    for(ll i=1;i<maxn;i++){
        dp[i]=dp[i-1]*(i-1)+1;
        dp[i]%=mod;
    }
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}