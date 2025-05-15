#include<bits/stdc++.h>

using namespace std;
#define maxn (int)5e3+3
typedef long long ll;
ll dp[maxn][maxn];

ll solve(vector<int>& arr,int i,int j){
    if(i==j)return arr[i];
    if(i>j) return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    ll res1=arr[i]+min(solve(arr,i+1,j-1),solve(arr,i+2,j));
    ll res2=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));
    return dp[i][j]=max(res1,res2);
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < maxn; i++) {
        memset(dp[i], -1, sizeof(dp[0]));
    }
    cout << solve(arr, 0, n - 1);
}