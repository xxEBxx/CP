#include<bits/stdc++.h>

using namespace std;
const int maxn=20 ;
int n, lx[maxn],ly[maxn],ax[maxn],ay[maxn] ,dp[maxn+5][(1<<maxn) +5];

int distance( int a,int b){ 
    return (abs(ax[a]-lx[b])+abs(ay[a]-ly[b]));
}
//we will fix leaf and search their best oppponents(aktski)
int solve(int i , int mask){
    if (i==n) return 0;
    if (dp[i][mask] != -1 ) return dp[i][mask];
    int ans=2e9;
    for (int j=0;j<n;j++){
        // we search for the bit in index i from the mask :
        int bit_value = (mask >> j) & 1;
        if (bit_value==0){
            ans=min(ans,distance(i,j) + solve(i+1,mask | (1<<j) ));
        }
    }
    return dp[i][mask]=ans;
}

int main (){
    cin>>n;
    for (int i=0;i<n;i++){
        scanf("%d %d",ax+i,ay+i);
    }
    for (int i=0;i<n;i++){
        scanf("%d %d",lx+i,ly+i);
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0);

}