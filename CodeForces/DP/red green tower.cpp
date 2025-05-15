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

const int maxn=(int)2*1e5+7;
const int mod =(int)1e9+7;
void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int dp[maxn][800];
int solve(int g,int level){
    if(g<0) return 0;
    if(level==0) return g==0;
    if(g==0)return 1;
    if(dp[g][level]!=-1)return dp[g][level];

    int res=solve(g-level,level-1);
    res+=solve(g,level-1);

    res%=mod;
    return dp[g][level]=res;
}

int ps(int i){
    return (i*(i+1)/2);
}
int main(){fast();
    memset(dp,-1,sizeof(dp));
    int r,g,sum;cin>>r>>g;
    sum=r+g;
    int level=0;
    while(sum>0){
        level++;
        sum-=level;
    }
    if(ps(level)!=r+g)level--;
    //cout<<level<<endl;

    int res=0;
    for(int green=g;g >= max(0,ps(level)-r);g--){
        res+=solve(green,level);
        res%=mod;
    }
    cout<<res<<endl;
    return 0;
}