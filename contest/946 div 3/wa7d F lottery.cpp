#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e3+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll n,k,arr[maxn],value[maxn],cost_general[2*maxn+3],cost[maxn],dp[maxn][12005];

ll solve(ll i,ll weight){
    if(weight > k)return (ll)-1e18;
    if(i==n)return 0;
    if(dp[i][weight]!=-1)return dp[i][weight];
    return dp[i][weight]=max(
                solve(i+1,weight),
                value[i]+solve(i+1,weight+cost[i])
        );
}

int main(){fast();
        cin>>n>>k;

        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)cin>>value[i];

        memset(dp,-1,sizeof(dp));
        for(int i=0;i<maxn;i++)cost_general[i]=20;

        cost_general[1]=0;
        for(int i=1;i<1001;i++){
            for(int z=i;z>=1;z--){
                cost_general[i+i/z]=min(cost_general[i+i/z],1+cost_general[i]);
                //cout<<cost_general[i+i/z]<<" "<<i+i/z<<" ";
            }
        }
        for(int i=0;i<n;i++) {
            cost[i] = cost_general[arr[i]];
            //cout<<cost[i]<<" ";
        }

        ll res=solve(0,0);

        if(res<-1000)cout<<0<<endl;
        else cout<<res<<endl;

    return 0;
}