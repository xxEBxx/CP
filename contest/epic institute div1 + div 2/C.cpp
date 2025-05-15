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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n),dp(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        dp[n-1]=arr[n-1];
        for(int i=n-2;i >= 0;i--){
            dp[i]=max(arr[i],1+dp[i+1]);

        }
        cout<<dp[0]<<endl;
    }
    return 0;
}