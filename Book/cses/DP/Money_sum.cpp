#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
    vector<int> dp(sum+2,0);
    for(int i=0;i<n;i++){
        //cout<<"here is dp[11] before i :"<<dp[11]<<" "<<i<<endl;
        for(int x=1;x<sum+1;x++){
            if (dp[x] == 2 && dp[x+arr[i]]!=2)dp[x+arr[i]] = 1;
            else if (x == arr[i])dp[x] = 1;
        }
        //cout<<"here is dp[11] before i :"<<dp[11]<<" "<<i<<endl;

        for(int x=1;x<sum+1;x++){
            if (dp[x] ==1)dp[x]++;
        }
        //cout<<"here is dp after "<<arr[i]<<" : ";
        /*for(int x=1;x<sum+1;x++){
            cout<<dp[x]<<" ";
        }
        cout<<endl;
        */
         }
    vector<int> res;
    for(int x=1;x<sum+1;x++){
        if(dp[x]==2){
            res.push_back(x);
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}

