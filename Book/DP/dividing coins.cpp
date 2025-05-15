//link : https://vjudge.net/problem/UVA-562

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
int dp[101][50005],arr[101],n,total;

//Here the states are index and price so far , the value will be the difference between
// the two either taking them or not , we want the minimal value because it means the minimum difference
int solve(int i ,int curr){
    if (i==n) return abs(curr-(total-curr));
    if (dp[i][curr]!=-1) return dp[i][curr];
    return dp[i][curr]=
            min(
                    solve(i+1,curr),
                    solve(i+1,curr+arr[i])
                    );
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        total=0;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            total+=arr[i];
        }
        cout<<solve(0,0)<<endl;
    }
    return 0;
}