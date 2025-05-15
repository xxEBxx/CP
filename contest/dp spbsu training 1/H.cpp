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

const int maxn=102;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,n1,n2,n3,dp[maxn][maxn][maxn],arr[maxn];

int solve(int n1,int n2,int n3){
    if(dp[n1][n2][n3]!=-1)return dp[n1][n2][n3];

    int other_win=0;
    for(int i=0;i<n;i++){
        if(arr[i] <= n1)other_win|=solve(n1-arr[i],n2,n3);
        if(arr[i] <= n2)other_win|=solve(n1,n2-arr[i],n3);
        if(arr[i] <= n3)other_win|=solve(n1,n2,n3-arr[i]);
    }

    return dp[n1][n2][n3]=dp[n2][n1][n3]=dp[n3][n2][n1]=1-other_win;
}
int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n1>>n2>>n3>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    if(solve(n1,n2,n3)==0)cout<<"Peter";
    else cout<<"Vasya";
    return 0;
}