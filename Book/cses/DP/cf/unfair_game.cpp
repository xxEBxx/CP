//link : https://codeforces.com/problemset/problem/1955/F

#include<bits/stdc++.h>
const int maxn=401;
using namespace std;
vector<vector<int>> dp(maxn,vector<int> (maxn,0));

int main(){
    int t;cin>>t;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            if(i&1 || j&1)dp[i][j]=0;
            else dp[i][j]=1;
        }
    }
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;

        cout<<((a/2+1)*(b/2+1)*(c/2+1)-1)/2<<endl;
    }
}