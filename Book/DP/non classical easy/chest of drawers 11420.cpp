#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define mem(v,x) memset(v,x,sizeof(v))

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
const int maxn=67;
vector<vector<vector<ll>>> dp(maxn,vector<vector<ll>> (maxn,vector<ll>(2,-1)));
ll n,s;

ll solve(ll i,ll secured,ll last_locked){
    if(i==n)return s==secured;
    if(dp[i][secured][last_locked]!=-1)return dp[i][secured][last_locked];

    if(last_locked==0)return dp[i][secured][last_locked]=
            solve(i+1,secured+1,0)+
            solve(i+1,secured,1);

    else return dp[i][secured][last_locked]=
            solve(i+1,secured,0)+
            solve(i+1,secured,1);

}

int main(){fast();
    while(cin>>n>>s){
        if(n<0)break;
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++){
            dp[i][j][0]=-1;dp[i][j][1]=-1;
        }
        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}