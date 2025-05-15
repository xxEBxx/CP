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

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

vector<ll> w,l;
ll n,k;
ll dp[maxn][maxn];
ll solve(ll i,ll j){
    if(i==n)
        return 0;
    if(k==j)
        return 1e18;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll width = 0,lentgh = 0, res = 1e18;
    for(ll index = i;index<n;index++){
        width += w[i];
        lentgh = max(lentgh,l[i]);
        res = min(res,  width*lentgh + solve(index+1,j+1) );
    }
    return dp[i][j]=res;
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;w.assign(n,0);
    l.assign(n,0);
    for(ll i=0;i<n;i++){
        cin>>w[i]>>l[i];
    }
    cout<<solve(0,0)<<endl;
    return 0;
}