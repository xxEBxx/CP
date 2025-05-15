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

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n;
map<int,vi> g;
int dp[maxn];

int solve(int i){
    if(i==0)return 1;
    if(dp[i]!=-1)return dp[i];
    int res=0;
    for(int elem : g[i]){
        res+=solve(elem);
    }
    return dp[i]=res;
}

int main(){fast();
    bool first=true;
    while(cin>>n){
        if(!first)cout << endl;
        else first=false;
        memset(dp,-1,sizeof(dp));
        g.clear();
        for(int i=1;i<=n;i++){
            int m;cin>>m;
            //cout<<"here is m"<<m<<endl;
            for(int j=1;j<=m;j++){
                int val;cin>>val;
                g[i].push_back(val+1);
            }
            if(m==0)g[i].push_back(0);
        }
        cout<<solve(1)<<endl;
        getchar();
    }
    return 0;
}

