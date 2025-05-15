//link : https://codeforces.com/problemset/problem/1771/B

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        unordered_map<int,int> hate;
        //highest hater
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            if(a < b) {
                int temp=a;
                a=b;
                b=temp;
            }
            if(hate[a] < b)hate[a]=b;
        }
        vector<int> dp(n+1,0);
        ll res=0;
        dp[1]=1;
        //cout<<dp[1]<<" ";
        for(int i=2;i<n+1;i++){
            dp[i]=min(i-hate[i],dp[i-1]+1);
            res+=dp[i];
            //cout<<dp[i]<<" ";
        }
        cout<<res+1<<endl;

     }
}