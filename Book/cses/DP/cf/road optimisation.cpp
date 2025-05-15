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

const ll maxn=501;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll n,k,l,dp[maxn][maxn],d[maxn],t[maxn];
//states are minimum time to arrive to stop i using j removals

ll solve(ll i,ll jumps){
    if(jumps > k)
        return 1e9;
    if(i==n){
        return 0;
    }
    if(i>n)
        return 1e9;

    if(dp[i][jumps]!=-1)
        return dp[i][jumps];

    ll res=1e9;
    for(ll index=i+1;index <= min(n,i+k+1);index++){
        res=min(res,
                (d[index]-d[i])*t[i]+solve(index,jumps+index-i-1));
    }
    return dp[i][jumps]=res;
}

int main(){fast();
    cin>>n>>l>>k;
    for(ll i=0;i<n;i++)
        cin>>d[i];
    d[n]=l;
    for(ll i=0;i<n;i++)
        cin>>t[i];
    for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)dp[i][j]=-1;

    cout<<solve(0,0)<<endl;
    return 0;
}