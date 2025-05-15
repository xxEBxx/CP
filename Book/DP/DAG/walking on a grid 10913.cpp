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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=77,maxm=77,min_val=-1000000000;

int n,m,arr[maxn][maxn],dp[maxn][maxn][7][3];

int solve(int i,int j,int k,int from){
    if(k > m)return min_val;
    if(i<0 || j<0 ||j>=n||i>=n)return min_val;
    if(i==n-1 && j==n-1) {
        int isneg=0;
        if(arr[i][j]<0)isneg=1;
        if(k+isneg > m)return min_val;
        return arr[i][j];
    }
    if(dp[i][j][k][from]!=-1)return dp[i][j][k][from];

    int res=min_val;
    int add=0;
    if(arr[i][j]<0)add=1;
    //0 is from top , 1 from left ,2 from right

    if(from==0){
        res = max(res, solve(i + 1, j, k + add,0));
        res = max(res, solve(i, j - 1, k + add,2));
        res = max(res, solve(i, j + 1, k + add,1));
    }
    else if(from==1){
        res = max(res, solve(i, j + 1, k + add,1));
        res = max(res, solve(i + 1, j, k + add,0));
    }
    else {
        res = max(res, solve(i + 1, j, k + add,0));
        res = max(res, solve(i, j - 1, k + add,2));
    }

    return dp[i][j][k][from] = res+arr[i][j];
}

int main(){fast();
    int tt=0;
    while(cin>>n>>m){tt++;
        if(n==0)break;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>arr[i][j];
        }
        int res;
        res=solve(0,0,0,0);
        cout<<"Case "<<tt<<": ";
        if(res < -10000000)cout<<"impossible"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}