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
ll pw3[11];
void pre(){
    pw3[0]=1;
    for(ll i=1;i<11;i++){
        pw3[i]=pw3[i-1]*3;
    }
}
int main(){fast();
    pre();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(1+n);
        for(ll i=1;i<1+n;i++){
            cin>>arr[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll>(pw3[10]+2,-1e18));
        //we arrived to index i with mask in base 3 mask
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=0ll;
            for(int mask=0;mask<pw3[10];mask++){
                dp[i][mask]=max(dp[i][mask],dp[i-1][mask]);
                //we see if it is valid
                bool valid=true;
                ll curr=arr[i],nmask=mask;
                while(curr){
                    ll digit=curr%10;
                    curr=curr / 10;
                    if(nmask/pw3[digit] % 3==2){
                        valid=false;
                        break;
                    }
                    else{
                        nmask+=pw3[digit];
                    }

                }
                if(valid) {
                    dp[i][nmask] = max(dp[i][nmask], dp[i-1][mask] + arr[i]);
                    //if(dp[i][nmask]>0)cout<<i<<" "<<nmask<<" "<<dp[i][nmask]<<endl;
                }
            }
        }
        ll res=0;
        for(int mask=0;mask<pw3[10];mask++){
            res=max(res,dp[n][mask]);
        }
        cout<<res<<endl;
    }
    return 0;
}