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
int n,m,dp[102][102];
map<ii,vector<ii>> g;

int solve(int i,int j){
    if( g[{i,j}].empty() ) return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int res=0;
    for(auto elem : g[{i,j}] ){
        res=max(res,solve(elem.f,elem.s));
    }
    return dp[i][j]=1+res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        g.clear();
        memset(dp,-1,sizeof(dp));
        string name;cin>>name;
        cin>>n>>m;
        vvi arr(n,vi(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ cin >> arr[i][j]; }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j<m-1){
                    if(arr[i][j] > arr[i][j+1])g[make_pair(i,j)].push_back(make_pair(i,j+1));
                    if(arr[i][j] < arr[i][j+1])g[{i,j+1}].push_back({i,j});
                }
                if(i<n-1){
                    if(arr[i][j]>arr[i+1][j])g[{i,j}].push_back({i+1,j});
                    if(arr[i][j]<arr[i+1][j])g[{i+1,j}].push_back({i,j});
                }
            }
        }
        //dag is ready
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,solve(i,j));
            }
        }
        cout<<name<<": "<<res<<endl;
    }
    return 0;
}