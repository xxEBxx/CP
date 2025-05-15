#include<bits/stdc++.h>
//undone
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,h;cin>>n>>h;
        int g=2,b=1;
        vector<int> arr(n);
        vector<vector<int>> dp(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(h > arr[i]){
                h+=arr[i]/2;
            }
            int bitmask=3*b+g;//0,1,2,3,4,5
            int res=1e9+2;
            if(bitmask%3 >= 1)res=min(res,dp[i-1][bitmask-1]);
            if(bitmask>=3)res=min(res,dp[i-1][bitmask-3]);
            if (bitmask%3==2)res=min(res,dp[i-1][bitmask-2]);
            if (bitmask>=4)res=min(res,dp[i-1][bitmask-4]);
            if(bitmask==5)res=min(res,dp[i-1][bitmask-5]);

            if(res>1e9)break;
        }
    }
}