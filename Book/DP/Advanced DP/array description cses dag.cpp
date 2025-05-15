#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=100007;
const int mod=(int)1e9+7;
int n,m,dp[maxn][102],arr[maxn];

int solve(int index,int number){
    if(number > m || number < 1)return 0;
    if(index==n-1)return 1;
    if(dp[index][number]!=-1)return dp[index][number]%mod;
    //we suppose our index number is valid;
    int res=0;

    if(arr[index+1]!=0){
        //next one is known
        if(abs(arr[index+1]-number) > 1)return 0;
        else {
            res=solve(index + 1, arr[index + 1])%mod;
            return dp[index][number] =  res; }
    }
    //here next element is 0 so we do 3 of them
    res+=solve(index+1,number-1);
    res%=mod;
    res+=solve(index+1,number);
    res%=mod;
    res+=solve(index+1,number+1);
    res%=mod;
    return dp[index][number]=res%mod;
}

int main(){fast();
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=0;
    if(arr[0]==0){
        for(int i=1;i<=m;i++) { res += solve(0, i);

        res%=mod;}
    }
    else res+=solve(0,arr[0]);
    cout<<res;
    return 0;
}