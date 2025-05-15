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

int v1,v2,n,d,dp[103][1003];

int solve(int i,int v){
    if(v>1000 || v<= 0)return -100000;
    if(i==n) {
        if(v == v2)return v;
        return -100000;
    }
    if(dp[i][v]!=-1)return dp[i][v];
    int res=0;
    for(int index = 0;index <= d ; index++){
        res=max(res,solve(i+1,v+index));
        res=max(res,solve(i+1,v-index));
    }
    if(res > 0)res+=v;
    return dp[i][v]=res;
}

int main(){fast();
    cin>>v1>>v2>>n>>d;
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,v1)<<endl;
    return 0;
}