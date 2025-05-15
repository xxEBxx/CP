//link : https://codeforces.com/problemset/problem/1706/C
#include<bits/stdc++.h>

using namespace std;
const int maxn=(int) 1e5+2;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> arr(n),dp(n+1);
        for(ll &a:arr)cin>>a;
        dp[0]=0;
        dp[1]=max((ll)0,max(arr[0]+1-arr[1],arr[2]+1-arr[1]));
        //cout<<dp[0]<<" "<<dp[1]<<" ";
        for(int i=2;i<n-1;i++){
            //le moment que tu choisi un impaire , tous le reste est impaire
            if(i&1){
                dp[i]=dp[i-2] + max((ll)0,max(arr[i+1],arr[i-1])+1-arr[i]);
            }
            else{
                dp[i]=min(dp[i-1],
                          dp[i-2]+max((ll)0,max(arr[i-1],arr[i+1])+1-arr[i])
                          );
            }
            //cout<<dp[i]<<" ";
        }
        //cout<<endl;
        cout<<dp[n-2]<<endl;
    }
}