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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
vi arr;
int n,dp[maxn][2];

int solve(int i,int turn){
    if(i >= n)
        return 0;
    if(dp[i][turn]!=-1)
        return dp[i][turn];

    int res;
    if(turn==0){
        res=min(solve(i+1,1),solve(i+2,1));
    }
    else{
        res=arr[i]+solve(i+1,0);
        if(i<n-1 && arr[i+1]==0){
            res=min(res,arr[i]+arr[i+1]+solve(i+2,0));
        }
    }
    return dp[i][turn] = res;

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        arr.clear();
        for(int i=0;i<n;i++){
            int val;cin>>val;
            arr.push_back(val);
        }
        cout<<solve(0,1)<<endl;
    }
    return 0;
}