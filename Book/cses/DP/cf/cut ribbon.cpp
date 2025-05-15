//https://codeforces.com/problemset/problem/189/A
#include<bits/stdc++.h>

using namespace std;
int n,a,b,c;
const int maxn=4003;
vector<int> dp(maxn,-1);
int solve(int k){
    if(k==0) return 0;
    if(k<0)return -maxn;
    if(dp[k]!=-1)return dp[k];
    int res=max(solve(k-c)+1,max(solve(k-a)+1,solve(k-b)+1));
    return dp[k]=res;
}

int main(){
 cin>>n>>a>>b>>c;
 cout<<solve(n);
}
