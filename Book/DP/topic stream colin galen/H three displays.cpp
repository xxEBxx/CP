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

const int maxn=3001;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll dp[maxn][maxn][3],n,arr[maxn],cost[maxn];

ll solve(int i,int last_taken,int taken){
    if(taken==3)return 0;
    if(i==n)return 5*1e9;

    if(dp[i][last_taken][taken]!=-1)return dp[i][last_taken][taken];

    ll res=solve(i+1,last_taken,taken);
    if(arr[i] > arr[last_taken]){
        res=min(res,cost[i]+solve(i+1,i,taken+1));
    }
    return dp[i][last_taken][taken]=res;
}
int main(){fast();
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)cin>>cost[i];

    ll res=5*1e9;

    for(int i=0;i<n;i++){
        res = min(res,cost[i]+solve(i+1,i,1));
    }

    if(res >= (ll)5*1e9 ) cout<<-1;
    else cout<<res;

    return 0;
}