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
int n,m;
string a,b;
int dp[101][101];
int solve(int i,int j, int curr){
    if(i==n || m==j)return curr;
    if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j])return dp[i][j]=solve(i+1,j+1,curr+1);
    return dp[i][j]=max(
            solve(i+1,j,curr),
            solve(i,j+1,curr)
            );
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;
        n=a.size(),m=b.size();
        cout<<min(n,m)-solve(0,0,0)<<endl;

    }
    return 0;
}