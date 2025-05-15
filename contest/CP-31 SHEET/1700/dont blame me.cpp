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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;


int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        //dp.assign(n,vi(64,0));
        vvi dp(n,vi(64,0));
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<64;j++){
                dp[i][j] = dp[i-1][j];
            }
            dp[i][arr[i]]++;
            for(int j=0;j<64;j++){
                dp[i][j & arr[i]] += dp[i-1][j];
                dp[i][j & arr[i]] %= mod;
            }
        }
        int res=0;
        for(int i=0;i<64;i++){
            if(__builtin_popcount(i)==k){
                res+=dp[n-1][i];
                res%=mod;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}