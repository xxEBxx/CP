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

const int maxn=(int)1e4+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,k;
vi arr(maxn);
vvi dp(maxn,vi (102));

bool solve(int i,int sum){
    //index so far , sum so far , content is either yes or no
    if(i==n) return sum==0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int added=((sum+arr[i])%k+k)%k;
    int subbed=((sum-arr[i])%k+k)%k;
    return dp[i][sum]=solve(i+1,added) | solve(i+1,subbed);
    }

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++)for(int j=0;j<k;j++)dp[i][j]=-1;
        for(int i=0;i<n;i++)cin>>arr[i];
        bool ans=solve(0,0);
        if(ans)cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }
    return 0;
}