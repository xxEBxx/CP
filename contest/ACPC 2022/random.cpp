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

const int N=(int)1002;
const int mod=998244353;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[N][2*N][2][2];
//dp[index so far][number of used k][upper][lower] = number of components
int main(){fast();
    memset(dp,0,sizeof dp);
    dp[1][0][0][0]=1;
    dp[1][1][1][0]=2;
    dp[1][1][0][1]=2;
    dp[1][2][1][1]=1;

    for(int i=2;i<N;i++){
        //dp[i][0][0][0]=1;
        for(int k=0;k<2*N;k++){

            dp[i][k][0][0] += dp[i-1][k][0][0];
            dp[i][k][0][0] %= mod;
            dp[i][k][0][0] += dp[i-1][k][1][0];
            dp[i][k][0][0] %= mod;
            dp[i][k][0][0] += dp[i-1][k][0][1];
            dp[i][k][0][0] %= mod;
            dp[i][k][0][0] += dp[i-1][k][1][1] + 1;
            dp[i][k][0][0] %= mod;

            if(k>0){
                dp[i][k][0][1] += dp[i-1][k-1][0][0]+1;
                dp[i][k][0][1] %= mod;
                dp[i][k][0][1] += dp[i-1][k-1][1][1]+1;
                dp[i][k][0][1] %= mod;
                dp[i][k][0][1] += dp[i-1][k-1][0][1];
                dp[i][k][0][1] %= mod;
                dp[i][k][0][1] += dp[i-1][k-1][1][0]+2;
                dp[i][k][0][1] %= mod;

                dp[i][k][1][0] += dp[i-1][k-1][0][0]+1;
                dp[i][k][1][0] %= mod;
                dp[i][k][1][0] += dp[i-1][k-1][1][1]+1;
                dp[i][k][1][0] %= mod;
                dp[i][k][1][0] += dp[i-1][k-1][0][1]+2;
                dp[i][k][1][0] %= mod;
                dp[i][k][1][0] += dp[i-1][k-1][1][0];
                dp[i][k][1][0] %= mod;
            }
            if(k>1){
                dp[i][k][1][1] += dp[i-1][k-2][0][0]+1;
                dp[i][k][1][1] %= mod;
                dp[i][k][1][1] += dp[i-1][k-2][1][1];
                dp[i][k][1][1] %= mod;
                dp[i][k][1][1] += dp[i-1][k-2][0][1]+1;
                dp[i][k][1][1] %= mod;
                dp[i][k][1][1] += dp[i-1][k-2][1][0]+1;
                dp[i][k][1][1] %= mod;
            }

        }
    }
    int n,k,res=0;cin>>n>>k;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            res+=dp[n][k][i][j];
            res%=mod;
        }
    }
    cout<<res<<endl;
    return 0;
}