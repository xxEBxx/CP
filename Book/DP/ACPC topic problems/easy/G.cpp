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

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,dp[maxn][4];

string s,base="scpc";

int solve(int i,int j){
    if(j==4)return 0;
    if(i==n)return 10;
    if(dp[i][j] != -1)return dp[i][j];
    int res1,res2;

    res1=solve(i+1,j);
    res2=solve(i+1,j+1)+(s[i] != base[j]);//we have a new problem

    return dp[i][j]=min(res1,res2);
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        cin>>s;
        cout<<solve(0,0)<<endl;
    }
    return 0;
}