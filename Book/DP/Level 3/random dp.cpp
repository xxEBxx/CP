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

map<int,set<int>> g,g_bid;
int dp[maxn],visited[maxn];

int dfs(int i){
    int res=0;
    visited[i]=1;
    for(int child:g_bid[i]){
        if(visited[child]==0){
            if(g[child].find(i)!=g[child].end()){
                res++;
            }
            res+=dfs(child);
        }
    }
    return res;
}
int n;

void dfs1(int p,int c){
    if(dp[c]!=-1)return ;

    if(g[p].find(c)!=g[p].end())
        //p is the parent
            dp[c]=dp[p]+1;

    else dp[c]=dp[p]-1;

    for(int elem:g_bid[c]){
        dfs1(c,elem);
    }
}

int main(){fast();
   cin>>n;
   memset(dp,-1,sizeof(dp));
    memset(visited,0,sizeof(visited));

    vector<int> arr(n);
   for(int i=0;i<n-1;i++){
       int p,c;cin>>p>>c;
       g[p].insert(c);
       g_bid[p].insert(c);
       g_bid[c].insert(p);
   }

   dp[1]=dfs(1);
   //cout<<dp[1]<<endl;
   for(int elem:g_bid[1])dfs1(1,elem);
   int res=1e9;
   for(int i=1;i<=n;i++)if(dp[i]<res)res=dp[i];
   cout<<res<<endl;
   for(int i=1;i<=n;i++)if(dp[i]==res)cout<<i<<" ";cout<<endl;

   return 0;
}