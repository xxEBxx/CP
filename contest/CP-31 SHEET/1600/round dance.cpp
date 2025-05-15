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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

unordered_map<int,set<int>> g;
vi visited;

int dfs(int i){
    int res=(int)g[i].size();
    visited[i]=1;
    for(auto child : g[i]){
        if(visited[child])continue;
        res=min(dfs(child),res);
    }
    return res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(1+n);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        visited.assign(n+1,0);
        g.clear();
        for(int i=1;i<=n;i++){
            g[i].insert(arr[i]);
            g[arr[i]].insert(i);
        }
        int cycle=0,pot=0;
        for(int i=1;i<=n;i++){
            if(visited[i] == 1)continue;
            if(dfs(i)==2)
                cycle++;
            else
                pot++;
        }
        cout<<cycle+(pot>0)<<" "<<cycle+pot<<endl;
    }
    return 0;
}