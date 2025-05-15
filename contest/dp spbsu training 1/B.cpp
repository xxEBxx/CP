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

const int maxn=20;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll n,b;
vector<ll> next_project,cost,revenue;
ll dp[maxn][(1<<maxn)+2];

ll solve(ll index,ll mask){
    if(index==n) {
        ll spent=0;
        for(int i=0;i<21;i++){
            if(mask & (1<<i))spent+=cost[i];
        }
        if(spent >  b)return -1e17;
        return 0;
    }
    if(dp[index][mask]!=-1)return dp[index][mask];
    //maximize revenue
    ll res=max(
            revenue[index]+solve(next_project[index],mask |(1<<index)),
            solve(index+1,mask)
            );
    return dp[index][mask]=res;
}

int main(){fast();
    memset(dp,-1, sizeof(dp));
    cin>>n>>b;
    ll count=0;
    for(int i=0;i<n;i++){
        ll k;cin>>k;
        count+=k;
        for(int j=0;j<k;j++){
            next_project.push_back(count);
            ll r,e;cin>>r>>e;
            revenue.push_back(r);
            cost.push_back(e);
        }
    }
    n=count;
    cout<<solve(0,0)<<endl;
    return 0;
}