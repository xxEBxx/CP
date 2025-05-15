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

const int maxn=5003;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll dp[maxn][maxn],arr[maxn],n;

ll solve(ll i,ll j,ll index){
    if(i==j)return index*arr[i];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=max(
            index*arr[i] + solve(i+1,j,index+1),
            index*arr[j] + solve(i,j-1,index+1)
            );
}

int main(){fast();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n-1,1);
    return 0;
}