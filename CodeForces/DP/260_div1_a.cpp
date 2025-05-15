#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int Long;
const int maxn=1e5+5;
Long n,a[maxn],cnt[maxn];
Long dp[maxn];

Long solve(Long x){
    if (x >= maxn) return 0;
    if (dp[x] >= 0) return dp[x ];
    
    Long ans= max(cnt[x]*x + solve(x+2),solve(x+1));
    return dp[x]=ans;
}

int main(){
    Long value;
    cin>>n;
    for (int i=1 ;i<n+1;i++){
        cin>>value;
        a[i]=value;
        cnt[a[i]]++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(1)<<endl;

    return 0;
}