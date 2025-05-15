#include<bits/stdc++.h>

using namespace std;
const int mod=(int)1e9+7;
const int maxn=3* (int) 1e5 +7;
vector<int> dp(maxn,0),
            facto(maxn,0);

int main(){
    dp[1]=1;dp[2]=3;
    facto[1]=1;facto[2]=2;
    for(int i=3;i<maxn;i++){
        facto[i]=i*facto[i-1];
        dp[i]=(i*i-i)*dp[i-2]/2+(i-1)*dp[i-1];
    }
    for(int i=1;i<10;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=0;i<m;i++){
            int a,b;cin >>a>>b;
            if(a==b)n--;
            else n-=2;
        }
        cout<<dp[n]<<endl;
    }
}