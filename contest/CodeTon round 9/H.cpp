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

const ll N=2002;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll n,m;
vector<ll> arr,b,c;
ll dp[N][N];
const ll inf=1000000000000000;
ll solve(ll i,ll j){
    if(j==m){
        if(i==n)
            return 0;
        return c[i]+solve(i+1,j);
    }
    if(i==n)
        return 1e15;
    if(dp[i][j] != -inf)
        return dp[i][j];
    ll res = c[i] + solve(i+1,j);
    if(arr[i]==b[j]){
        res = min(res,solve(i+1,j+1));
    }
    return dp[i][j]=res;
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        cin>>n>>m;
        arr.resize(n);b.resize(m);c.resize(n);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j]=-inf;
            }
        }
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<m;i++)
            cin>>b[i];
        for(ll i=0;i<n;i++)
            cin>>c[i];
        cout<<solve(0,0)<<endl;


    }
    return 0;
}