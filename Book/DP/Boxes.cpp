//link : https://vjudge.net/problem/UVA-11003

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

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int dp[101][50005],weight[101],capacity[101],n,total;

//Here the states are index and price so far , the value will be the difference between
// the two either taking them or not , we want the minimal value because it means the minimum difference
int solve(int i ,int curr,int possible_weight){
    //curr keep track of the weight
    if (i==n) return 0;
    if(possible_weight < 0) return 0;

    if (dp[i][curr]!=-1) return dp[i][curr];

    int notake=solve(i+1,curr,possible_weight),take=0;
    if(possible_weight >= weight[i]){
        take=solve(i+1,curr)
    }
    return dp[i][curr]=
                   min(
                           solve(i+1,curr),
                           1+solve(i+1,curr+arr[i])
                   );
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        total=0;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>weight[i]>>capacity[i];
        }
        cout<<solve(0,0,1e9)<<endl;
    }
    return 0;
}