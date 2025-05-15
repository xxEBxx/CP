//link : https://vjudge.net/problem/UVA-357
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
int coins[]={1,5,10,25,50};
ll dp[5][30006];
ll solve(ll i,ll num){
    if(num==0)return 1;
    if(num<0 || i==5) return 0;
    if(dp[i][num]!=-1)return dp[i][num];
    return dp[i][num]=  solve(i,num-coins[i])+
                        solve(i+1,num);
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    ll n;
    while(cin>>n){
        if(solve(0,n)==1)cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        else cout<<"There are "<<solve(0,n)<<" ways to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}