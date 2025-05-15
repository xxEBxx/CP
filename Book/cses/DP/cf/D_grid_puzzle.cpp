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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[maxn][2][2],n,arr[maxn];

int solve(int i , int x,int y){
    if(i==n)
        return 0;
    if(dp[i][x][y]!=-1)
        return dp[i][x][y];

    int res= 1+solve(i+1,0,0);

    if(arr[i]==0)
        res=solve(i+1,0,0);
    else if(arr[i] <= 2){
        if(x)
            res=min(res,solve(i+1,0,0));
        else
            res=min(res,1+solve(i+1,1,0));
    }
    else if(arr[i] <= 4){
        if(x)
            res=min(res,1+solve(i+1,0,1));
        else if(y)
            res=min(res,1+solve(i+1,1,0));
    }

    return dp[i][x][y]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}