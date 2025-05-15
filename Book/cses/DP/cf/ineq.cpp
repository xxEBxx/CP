#include<bits/stdc++.h>

using namespace std;
const int maxn=2*1e5+3;
typedef long long ll;
ll dp[maxn];

int main(){
    int t;cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        vector<int> arr(n);
        for(int &k:arr)cin>>k;
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<n;i++){
            if(arr[i] < i )dp[i]=1+dp[i-1];
            else dp[i]=0;
        }
        cout<<dp[n-1]<<endl;
    }
}