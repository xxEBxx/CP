#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define maxn 1002
vector<vector<int>> dp(maxn,vector<int> (maxn,0));

int main(){
    int n;cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //cout<<arr[i]<<endl;
    }
    if(n<2){
        cout<<(arr[0][0]=='.')?1:0;
        return 0;
    }
    dp[0][0]=1;
    /*if(arr[0][1]!='.')dp[0][1]=1;
    if(arr[1][0]!='.')dp[1][0]=1;
    if(arr[1][1]!='.')dp[1][1]=1;*/
    for(int i = 0; i < n; i++) {
        if(arr[i][0] == '.') {
            dp[i + 1][0] = 1; // Note: i + 1 instead of i
            //cout<<i+1<<" "<<dp[i+1][0];
        } else {
            dp[i][0]=0;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[0][i] == '.') {
            dp[0][i + 1] = 1; // Note: i + 1 instead of i
            //cout<<i;
        } else {
            dp[0][i]=0;
            break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]=='*')continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    //cout<<"here is the dp matrix :";
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n-1][n-1];
    return 0;
}

