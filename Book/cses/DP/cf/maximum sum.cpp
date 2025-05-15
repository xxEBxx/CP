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

const int maxn=16;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[maxn][(1<<maxn)+1],n,arr[maxn][maxn];

int solve(int i,int bitmask){
    if(i==n)
        return 0;
    if(dp[i][bitmask] != -1)
        return dp[i][bitmask];

    int res=0;

    for(int index=0;index<n;index++){
        if((bitmask>>index)&1)continue;

        res=max(res,arr[i][index]+solve(i,bitmask))
    }

    return dp[i][bitmask]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
    return 0;
}