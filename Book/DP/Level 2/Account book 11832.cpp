#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=42,maxf=32000;
int n,f,arr[maxn],dp[maxn][maxf+2],offset=16000,can_neg[maxn],can_pos[maxn];

int solve(int i,int sum){
    //we give an i and number and see if we can achieve 0 by it
    if(i==n)return sum==f+offset;
    if(sum > maxf || sum < 0)return 0;
    if(dp[i][sum]!=-1)return dp[i][sum];
    int res=0;
    if(solve(i+1,sum-arr[i])) {
        can_neg[i] = 1;
        res=1;
    }
    if(solve(i+1,sum+arr[i])){
        can_pos[i]=1;
        res=1;
    }

    return dp[i][sum]=res;
}

int main(){fast();
    while(cin>>n>>f){
        if(n==0)break;
        memset(dp,-1,sizeof(dp));
        memset(can_neg,0,sizeof(can_neg));
        memset(can_pos,0,sizeof(can_pos));

        for(int i=0;i<n;i++)cin>>arr[i];

        int res=solve(0,offset);
        if(res==0)cout<<"*"<<endl;
        else{
            for(int i=0;i<n;i++){
                if(can_neg[i] && can_pos[i])cout<<"?";
                else if(can_neg[i])cout<<"-";
                else cout<<"+";
            }
            cout<<endl;
        }
    }
    return 0;
}