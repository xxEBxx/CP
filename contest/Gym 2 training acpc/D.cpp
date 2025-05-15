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

const ll maxn=801;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    ll maxsum=801*9;
    vvi dp(maxn,vi(maxsum,0));
    for(ll i=1;i<10;i++){
        dp[1][i]=1;
    }
    for(ll i=2;i<801;i++){
        for(ll j=1;j<maxsum;j++){
            for(ll k=max(1LL,j-9);k<=j;k++) {
                dp[i][j] += dp[i - 1][k];
                //dp[i][j] %= mod;
            }
            for(int k=0;k<=9;k++){
                if(j-k>=0)
                    dp[i][j] -= dp[i-1][j-k]* (dp[i-1][j-k]-1)/2;
            }
        }
    }


    while(t--) {
        ll n;
        cin >> n;
        ll res=0;
        for(ll i=0;i<maxsum;i++){
            if(dp[n][i]==0)continue;
            res += dp[n][i]* (dp[n][i]-1)/2;

            res %= mod;
        }
        cout<<res<<endl;
    }
    return 0;
}
