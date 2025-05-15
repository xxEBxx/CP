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

const int N=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,m;
map<int,vi> g1,g2,g3;

void dfs(int v,int p){
    if(v>m){
        for(int elem:g1[v]){
            if(elem==p)continue;
            g3[p].push_back(elem);
            g3[elem].push_back(p);
        }
    }
    for(int elem : g1[v]){
        if(elem==p)continue;
        if(elem<=m && v<=m){
            g3[v].push_back(elem);
            g3[elem].push_back(v);
        }
        dfs(elem,v);
    }
}

int parent2[N],parent3[N];
void dfs2(int v,int p){
    parent2[v]=p;
    for(int elem:g2[v]){
        if(elem==p)continue;
        dfs2(elem,v);
    }
}

void dfs3(int v,int p){
    parent3[v]=p;
    for(int elem:g3[v]){
        if(elem==p)continue;
        dfs3(elem,v);
    }
}

int main(){fast();
    ifstream cin("tree.in");
    int t;cin>>t;
    while(t--){
        g1.clear();g2.clear();g3.clear();
        cin>>n>>m;//from m+1 to n
        vector<int> arr(n);
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            g1[a].push_back(b);
            g1[b].push_back(a);
        }
        for(int i=0;i<m-1;i++){
            int a,b;cin>>a>>b;
            g2[a].push_back(b);
            g2[b].push_back(a);
        }

        dfs(1,1);
        dfs2(1,1);
        dfs3(1,1);
        string res="YES";
        for(int i=1;i<=m;i++)cout<<parent2[i]<<" ";cout<<endl;
        for(int i=1;i<=m;i++)cout<<parent3[i]<<" ";cout<<endl;
        for(int i=1;i<=m;i++){
            if(parent2[i] != parent3[i]){
                res="NO";
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}