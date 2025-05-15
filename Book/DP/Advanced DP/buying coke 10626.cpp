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

int dp[151][51][151];

int solve(int five,int ten,int to_buy){
    //as ones can be large , knowing these 3 states we can generate the 4th
    if(to_buy==0)return 0;
    if(dp[five][ten][to_buy]!=-1)return dp[five][ten][to_buy];
    int one=to_buy*8-five*5-ten*10;
    int res=1e9;
    if(ten)res=min(res,1+solve(five,ten-1,to_buy-1));
    if(five > 1)res=min(res,2+solve(five-2,ten,to_buy-1));
    if(one >= 3) {
        if(ten)res=min(res,4+solve(five+1,ten-1,to_buy-1));
        if(five)res = min(res,4+solve(five-1,ten,to_buy-1));
    }
    if(one >= 8){
        res=min(res,8+solve(five,ten,to_buy-1));
    }
    return dp[five][ten][to_buy]=res;
}

int main(){fast();
    int t;cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        int n;cin>>n;
        int a,b,c;cin>>a>>b>>c;
        cout<<solve(b,c,n)<<endl;
    }
    return 0;
}