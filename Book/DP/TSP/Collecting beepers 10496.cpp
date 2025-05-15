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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=10;
int dp[maxn][(1<<maxn)];
int n,dist[maxn+1][maxn+1];

int solve(int number,int mask){
    //number is the last element we saw , mask is a mask of element we already passed by
    if(mask==(1<<(n+1))-1) return dist[0][number];//go back from the last element to 0
    if(dp[number][mask]!=-1)return dp[number][mask];
    int res=1e9;
    for(int i=1;i<=n;i++){
        if( ! (mask & (1<<i)) ) {
            res = min(res,dist[number][i]+solve(i,mask | (1<<i)));
        }
    }
    return dp[number][mask]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        for(int i=0;i<maxn;i++)for(int j=0;j<(1<<maxn);j++)dp[i][j]=-1;

        int sizex,sizey;cin>>sizex>>sizey;
        //start from 0 and come back to 0
        vector<ii> arr(1);
        cin>>arr[0].f>>arr[0].s;
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dist[i][j]=abs(arr[i].f-arr[j].f)+abs(arr[i].s-arr[j].s);
            }
        }
        //WE HAVE N+1 elements
        int res=solve(0,1);
        cout<<"The shortest path has length ";
        cout<<res<<endl;
    }
    return 0;
}