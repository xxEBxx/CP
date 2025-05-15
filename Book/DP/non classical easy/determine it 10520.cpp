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
const int maxn=22;
int n,val;
vector<vector<ll>> dp(maxn,vector<ll>(maxn,-1));
ll solve(int i,int j){
    if(dp[i][j]!=-1)return dp[i][j];

    if(i<j){
        ll res=solve(i,i)+solve(i+1,j);
        for(int k=i+1;k<j;k++){
            res=max(res,solve(i,k)+solve(k+1,j));
        }
        return dp[i][j]=res;
    }

    ll res1,res2;

    if(i==n)res1=0;
    else{
        res1=solve(i+1,1)+solve(i+1,j);
        for(int k=i+2;k<=n;k++){
            res1=max(res1,solve(k,1)+solve(k,j));
        }
    }

    if(j<=1)res2=0;
    else{
        res2=solve(i,1)+solve(n,1);
        for(int k=2;k<j;k++){
            res2=max(res2,solve(i,k)+solve(n,k));
        }
    }
    return dp[i][j]=res1+res2;
}

int main(){fast();
    while(cin>>n>>val){
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++) { dp[i][j] = -1;dp[0][j]=0;dp[j][0]=0; }
        dp[n][1]=val;
        cout<<solve(1,n)<<endl;
    }
    return 0;
}