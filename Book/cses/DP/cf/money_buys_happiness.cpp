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
const ll max_h=50001;
int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        ll dp[max_h];
        ll bigg=1e12+2;
        vi price(51),happiness(51);
        for(ll i=0;i<=max_h;i++)dp[i]=bigg;
        for(ll i=0;i<n;i++){
            cin>>price[i]>>happiness[i];
        }

        dp[0]=0;
        for(ll i=0;i<n;i++){
//dp[i] is the minimum cost to buy i happines
            for(ll h=max_h ; h >= happiness[i];h--){
//we start from top to change each element once if possible
//if we start from bottom we risk taking an element twice
                if(dp[h-happiness[i]]+price[i] <= i*x){
                    dp[h]=min(dp[h],dp[h-happiness[i]]+price[i]);
                }
            }
        }
        for(ll i=50000;i>=0;i--){
            if(dp[i]==bigg)continue;
            cout<<i<<endl;
            break;
        }
        
    }
    return 0;
}