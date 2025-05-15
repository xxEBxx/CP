#include<bits/stdc++.h>
using namespace std;
#define maxn 1e6+5
#define inf 1e9
vector<int> dp(maxn,inf);

int find_kth(int k,int i){

    for(int j=0;j<i;j++){
        k/=10;
    }
    return k- (k/10)*10;
}

int main(){
    //cout<<find_kth(1234567,2);
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=1;

    for(int i=1;i<n+1;i++){
        int min_sub=inf;
        for(int kk=0;kk<7;kk++){
            min_sub=min(min_sub,dp[i-find_kth(i,kk)]);
        }
        dp[i]=min_sub+1;
    }

    cout<<dp[n];
}