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

const int maxn=100;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,arr[maxn],total,dp[maxn][45000][51];

int solve(int i,int sum,int taken){
    if(i==n){
        if(abs(n-taken - taken) > 1)return 1e9;
        return sum;
    }
    if(dp[i][sum][taken]!=-1)return dp[i][sum][taken];
    int res=1e9;
    res=min(
            solve(i+1,sum,taken),
            solve(i+1,sum+arr[i],taken+1)
            );
    return dp[i][sum][taken]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        total=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            total+=arr[i];
        }
        int sub2=total/2+total%2,sub1=total/2;
        int diff=solve(0,0,0);
        int diff1=diff/2+diff%2,diff2=diff/2;
        int sum1=diff1+sub1,sum2=sub2-;

    }
    return 0;
}