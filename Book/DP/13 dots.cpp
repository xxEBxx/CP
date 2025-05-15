//link :https://vjudge.net/problem/UVA-10819
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

int main(){fast();
    int n,max_money;
    while(cin>>max_money>>n){
        vector<ii> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].f>>arr[i].s;
            // here f is cost and s is value;
        }
        vector<vector<ii>> dp(n+1,vector<ii>(max_money+201,make_pair(0,0)));
        //first is the best value and second is minimum money lost to do so
        for(int mon=0;mon<=max_money;mon++){
            if(mon >= arr[0].f)dp[0][mon].f=arr[0].s;
        }
        for(int i=1;i<n;i++) {
            for (int j = 0; j <= max_money; j++) {
                dp[i][j] = dp[i - 1][j];//not taking ith
                if (j >= arr[i].f) { //can we get the ith
                    int take =dp[i - 1][j - arr[i].f].f + arr[i].s;
                    int no_take = dp[i][j].f;
                    if ( take > no_take) {
                        dp[i][j].f = take;
                        dp[i][j].s = j; //add the price spent
                    }
                }
            }
        }
        int res=0;
        for(int mon=0;mon<=max_money-200;mon++){
            res=max(res,dp[n-1][mon].f);
            if(dp[n-1][mon].s >= 1800){
                res=max(res,dp[n-1][mon+200].f);
            }
        }
    cout<<res<<endl;
    }
    return 0;
}