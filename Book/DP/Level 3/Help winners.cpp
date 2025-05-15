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

const ll maxn=16;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll dp[maxn][(1<<maxn)][2][2],n,arr[maxn][maxn];

ll solve(ll i,ll bitmask,ll super,ll invalid){
    if(i==n) {
        if(super==1 || invalid==0)return 1;
        return 0;
    }
    if(dp[i][bitmask][super][invalid]!=-1)return dp[i][bitmask][super][invalid];

    ll res=0;
    for(ll index=0;index<n;index++){
        if( ((bitmask>>index)&1) == 0 ){
            if(arr[i][index]==2 || super==1){
                res+=solve(i+1,bitmask | (1<<index),1,invalid);
            }
            else if(arr[i][index]==1){
                res+=solve(i+1,bitmask | (1<<index),super,invalid);
            }
            else{
                res+=solve(i+1,bitmask | (1<<index),super,1);
            }
        }
    }
    return dp[i][bitmask][super][invalid]=res;
}

int main(){fast();
    ll t;cin>>t;ll tt=0;
    while(t--){tt++;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++)cin>>arr[i][j];
        }
        cout<<"Case "<<tt<<": ";
        cout<<solve(0,0,0,0)<<endl;

    }
    return 0;
}