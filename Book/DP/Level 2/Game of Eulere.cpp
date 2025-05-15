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

int n,dp[16][16][16][16];

int check(int a,int b, int c,int d, int i,int j){
    if(i==0)return a & (1<<j) ;
    if(i==1)return b & (1<<j);
    if(i==2)return c & (1<<j) ;
    if(i==3)return d & (1<<j) ;
}

int solve(int a,int b,int c,int d){
    if(a==15 && b==15 && c==15 && d==15)
        return 1;//that person won
    if(dp[a][b][c][d]!=-1)return dp[a][b][c][d];
    //we try to find a way for the other to lose or we lose
    int res=0;
    //loosing position have all childs winning;
    if((a&8)==0){
        res=max(res,solve())
    }

    if(res)dp[a][b][c][d]=1;



}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    int t;cin>>t;
    vector<string> m(4);
    while(t--){
        for(int i=0;i<4;i++)cin>>m[i];
        int params[4];
        for(int i=0;i<4;i++){
            int bitmask=0;
            for(int j=0;j<4;j++){
                if(m[i][j]=='.'){
                    bitmask += (1<<(3-j));
                }
            }
            params[i]=bitmask;
        }
        int res=solve(params[0],params[1],params[2],params[3]);

    }
    return 0;
}