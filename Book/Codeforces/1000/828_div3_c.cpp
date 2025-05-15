#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        char c;cin>>c;
        string arr;cin>>arr;
        vector<int> dp(n,0);
        //find first green for the last element
        int i=0;
        if(arr[n-1]=='g'){
            dp[n-1]=0;
        }
        else{
            while (i < n && arr[i] != 'g') {
                i++;
            }
            dp[n-1]=i+1;
        }
        int current_green=dp[n-1]+1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]=='g'){
                current_green=0;
            }
            dp[i]=current_green;
            current_green++;
        }
        //cout<<"here is dp:";
        //for(int i=0;i<n;i++){
        //   cout<<dp[i]<<" ";
        //}
        //cout<<endl;
        int res=0;
        for(int i=0;i<n;i++){
            if(arr[i]==c && res < dp[i]){
                res=dp[i];
            }
        }
        cout<<res<<endl;
    }
}