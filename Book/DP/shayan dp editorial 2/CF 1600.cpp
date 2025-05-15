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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int t;cin>>t;
    while(t--){

        int n;cin>>n;
        vector<int> arr(n+1),dp(n+1,0);
        arr[0]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i-arr[i]-1>=0 && dp[i-arr[i]-1]==1){
                //it can be the len at the right of a group
                dp[i]=1;
            }
            if(dp[i-1]==1 && i+arr[i]<=n){
                dp[i+arr[i]]=1;
            }
        }

        if(dp[n]==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}