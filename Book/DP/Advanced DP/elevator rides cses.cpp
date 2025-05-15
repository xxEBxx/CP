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

const int maxn=21;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,max_weight,arr[maxn],dp[maxn][(1<<maxn)+3],res=0;
int solve(int i,int mask,int curr){
    if(mask == (1<<n)-1)return 0;
    if(curr > )
    if(dp[i][mask]!=-1)return dp[i][mask];
    int res=1e9;
//each time take a combination of elements (not taken before) whose sum is smaller than max_weight
    for(int index=i+1;i<n;i++){
        if((mask & (1<<index)) == 0){
            solve(i+1,mask|(1<<index),curr+arr[i]);
            solve(i+1,mask,curr);
        }
    }

}

int main(){fast();
    cin>>n>>max_weight;
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<solve(0,0);
    return 0;
}