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

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[1002][1<<10],n,m;

int solve(int i,int bitmask){
    if(i==m){
        for(int index=0;index<n-1;index++){
            if( (bitmask>>index & 1) == 0 ){
                if( (bitmask>>(index+1) & 1) == 1)
                    return 0;
                else
                    return 1;
            }
        }
        return 1;
    }

    if(dp[i][bitmask]!=-1)
        return dp[i][bitmask];

    int next_bitmask=0;
//some elements will be fix the one 101 the 0 will be filled for sure
    for(int index=0;index<n;index++){
        if()
    }
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    return 0;
}