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

int n;
vi arr(101);
vvi dp(101,vi(64005,-1));
bool solve(int i,int number){
    if(i==n-1)return number==arr[n-1]+32000;
    if(dp[i][number]!=-1)return dp[i][number];
    int res1=0,res2=0,res3=0,res4=0;
    if(number+arr[i]<=64000)    res1=solve(i+1,number+arr[i]);
    if(number-arr[i]>=0)        res2=solve(i+1,number-arr[i]);
    if(number*arr[i]<=64000)    res3=solve(i+1,number*arr[i]);

}

int main(){fast();
    int t;cin>>t;
    while(t--){cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

    }
    return 0;
}