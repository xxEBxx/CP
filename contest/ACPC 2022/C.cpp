#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;cin >> t;
    while(t--){
        string n;cin >> n;
        vector<vector<int>> dp(n.size(),vector<int>(9,0));
        dp[0][(n[0]-'0')%9] = 1 ;
        if(n[0] == '2')dp[0][4] = 1;
        if(n[0] == '3')dp[0][0] = 1;

        for(int i=1;i<n.size();i++){
            for(int j=0;j<9;j++){
                if(dp[i-1][j]==0)continue;
                dp[i][(n[i]-'0'+j) %9] = 1;
                if(n[i] == '2')dp[i][(n[i]-'0'+j + 2)%9] = 1;
                if(n[i] == '3')dp[i][(n[i]-'0'+j + 6)%9] = 1;

            }
        }
        if(dp[n.size()-1][0])cout <<"YES"<<endl;
        else cout << "NO"<<endl;

    }




    return 0;
}