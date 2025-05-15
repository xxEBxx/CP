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

const int maxn=(int)1e5*2+7;

int dp[maxn][2][2],n,arr[maxn];
//states are index so far, did i use block at the begining , did i use it at the end
int solve(int index,int start,int end){
    if(index==n)return 0;
    if(dp[index][start][end] != -1)return dp[index][start][index];

    int res= 1 + solve(index+1,0,0);
    if(index==3 && end==0 && start==0){
        cout<<res<<endl;
        cout<<solve(index+1,0,0)<<endl;
    }
    if(arr[index]==0 || (start && arr[index]<=2))res=min(res,solve(index+1,0,0));
    if(index==2 && end==1){
        cout<<res<<endl;
    }
    if(arr[index]==1 || arr[index]==2)
        res=min(res, 1 + solve(index+1,1,0));
    if(index==2 && end==1){
        cout<<res<<endl;
    }
    if(arr[index] ==3 || arr[index]==4){//try to do line start or end
        if(start)   res=min(res,1+solve(index+1,0,1));
        if(end)     res=min(res,1+solve(index+1,1,0));
    }
    if(index==2 && end==1){
        cout<<res<<endl;
    }

    return dp[index][start][end] =res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(0,0,0);
    }
    return 0;
}