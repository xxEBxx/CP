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

const int maxn=603,maxm=303;
int n,m,dp[maxn][maxm];
vi arr,ps;//these are the edges;
map<int,vi> g;//each element is assigned to all next elements with the prices

int distance(int i,int j){
    if(i==0) return ps[j];
    return ps[j]-ps[i];
}

int solve(int index,int k){
    //index is the vertex and k is the number of nights we have left
    if(k > m+1)return 1e9;
    if(index==n ) {
        if (k == m+1) return 0;
        else return 1e9;
    }
    if(dp[index][k]!=-1)return dp[index][k];
    int res=100000000;
    for(int elem : g[index]){
        //cout<<"here is distance "<<index<<" "<<elem<<" "<<distance(index,elem)<<endl;
        res= min( res , max( distance(index,elem) , solve(elem,k+1) ));
    }
    return dp[index][k]=res;
}

int main(){fast();
    while(cin>>n>>m){
        memset(dp,-1,sizeof(dp));
        n++;
        arr.clear();
        ps.clear();

        arr.push_back(0);
        ps.push_back(0);
        for(int i=1;i<=n;i++){
            int v;cin>>v;
            arr.push_back(v);
            ps.push_back(ps[i-1]+v);
        }

        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                g[i].push_back(j);
            }
        }

        cout<<solve(0,0)<<endl;
    }
    return 0;
}