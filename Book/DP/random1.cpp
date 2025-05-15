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

int dp[maxn][11],k,n,arr[maxn];

int main(){fast();
    int t;cin>>t;
    while(t--){cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));

        dp[0][0]=arr[0];
        for(int i=1;i<k;i++){
            //using 0 elements
            for(int j=1;j <= k;j++)
                dp[i][0]=dp[i-1][0]+arr[i];
        }

        for(int j=1;j <= k;j++){
            for(int i=1;i<n;i++){
                dp[i][j]=dp[i][j-1];
                for(int use=1;use <= j;use++){
                    //try using the segments
                    dp[i][j] = min(dp[i][j], dp[i - j - 1][j-use-1] + use * min(arr[i],arr[i-use]));
                }
            }
        }

        cout<<dp[n-1][k]<<endl;

    }
    return 0;
}