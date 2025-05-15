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

int n,dp[51][21],ps[51][21],arr[51][21],max_elems[51];

priority_queue<int> ans;

int solve(int i, int j){
    if(i==n)return 0;
    if(arr[i][j]==-1)
        return solve(i+1,0)+j;
    if(dp[i][j]!=-1)return dp[i][j];

    if(ps[i][j]!=max_elems[j])
        return dp[i][j]=solve(i,j+1);

    //either go to next element
    if(ps[i][j]==max_elems[j])
        ans.push(solve(i+1,0)+j);


}

int main(){fast();
    while(cin>>n){

        memset(dp,-1,sizeof(dp));
        //memset(ps,-1,sizeof(ps));
        memset(arr,-1,sizeof(arr));
        memset(max_elems,0,sizeof(max_elems));

        if(n==0)break;
        for(int i=0;i<n;i++){
            int m;cin>>m;
            for(int j=0;j<m;j++){
                cin>>arr[i][j];

                if(j==0)ps[i][j]=arr[i][j];
                else ps[i][j]=arr[i][j]+ps[i][j-1];

                max_elems[i]=max(max_elems[i],ps[i][j]);
            }
        }
    }
    return 0;
}