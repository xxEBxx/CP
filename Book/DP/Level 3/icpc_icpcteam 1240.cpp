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

const int maxn=12;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int arr1[maxn],arr2[maxn],arr3[maxn];
int dp[(1<<maxn)][281][4],n;

int solve(int bitmask,int time,int last_solver){
    if(time > 280)return -1e9;
    if(bitmask==((1<<maxn)-1))return 0;
    if(dp[bitmask][time][last_solver]!=-1)return dp[bitmask][time][last_solver];

    //either dont solve this problem or make one of the 3 solve it
    int res=0;
    for(int i=0;i<n;i++){
        if(((1<<i)&bitmask)==0){
            //res=max(res, solve(bitmask | (1<<i),time,last_solver));    //we should also consider not solving it

            if(last_solver!=1)res=max(res,1+solve(bitmask | (1<<i),time+arr1[i],1));
            if(last_solver!=2)res=max(res,1+solve(bitmask | (1<<i),time+arr2[i],2));
            if(last_solver!=3)res=max(res,1+solve(bitmask | (1<<i),time+arr3[i],3));
        }
    }

    return dp[bitmask][time][last_solver]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr1[i];
        for(int i=0;i<n;i++)cin>>arr2[i];
        for(int i=0;i<n;i++)cin>>arr3[i];
        cout<<solve(0,0,0)<<endl;

    }
    return 0;
}