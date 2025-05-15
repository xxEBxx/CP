#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=3*1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,k,leaf[maxn],dp[maxn],parent[maxn],weight[maxn];

int solve(int v,set<int> s){
    if(v==0) {
        s.insert(v);
        int res=0;
        for(int kk:s)res+=kk;
        return res;
    }
    if(dp[v]!=-1)return dp[v];
    //we try to insert our element
    s.insert(v);
    int removed=-1;
    if(s.size() > k) {
        removed=*s.begin();
        s.erase(s.begin());
    }
    int res=0;

    for(int elem:s)res+=elem;

    s.erase(v);
    if(removed!=-1)s.insert(removed);

    return dp[v]=res;
}

int main(){fast();
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    memset(leaf,1,sizeof(leaf));
    for(int i=0;i<n;i++){
        int p,c;cin>>p>>c;
        parent[i]=p;
        weight[i]=c;
        leaf[p]=0;
    }
    int res=0;
    for(int i=0;i<n;i++)res=max(res,solve(i,{}));
    cout<<res<<endl;
    return 0;
}