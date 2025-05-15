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

const int maxn=16;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[maxn][maxn],c[maxn],n;

int solve(int i, int allowed){
    if(i==n+1)
        return 0;
    if(c[i]==0)
        return solve(i+1,allowed);
    if(dp[i][allowed] != -1)
        return dp[i][allowed];

    int res=solve(i+1,allowed+1);
    //the one who wants to minimize let the other take the film
    if(allowed >= c[i] )
        res=max(res,1+solve(i+1,allowed-c[i]));

    return dp[i][allowed]=res;

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(c,0,sizeof(c));
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            c[val]++;
        }
        int all=0;
        for(int i=0;i<=n;i++)if(c[i] > 0)all++;
        cout<<all - solve(1,0)<<endl;
    }
    return 0;
}