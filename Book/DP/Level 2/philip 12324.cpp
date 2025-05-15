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

const int maxn=101;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,dp[maxn][maxn*maxn],arr[maxn],spheres[maxn];

int solve(int i,int num){
    if(i==n)return 0;
    if(dp[i][num]!=-1)return dp[i][num];

    int res=arr[i]+solve(i+1,num+spheres[i]);
    if(num > 0)res=min(res,arr[i]/2+solve(i+1,num-1+spheres[i]));
    return dp[i][num]=res;
}

int main(){fast();
    while(cin>>n){
        if(n==0)break;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>arr[i]>>spheres[i];
        }
        cout<<solve(0,0)<<endl;
    }
    return 0;
}