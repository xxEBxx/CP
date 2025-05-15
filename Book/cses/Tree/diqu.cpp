#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;
void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

vi parent(maxn,0);
vi depth(maxn,-1);
vi adj[maxn];
const int logg=19;
vvi up(maxn,vi(logg,-1));
//up[i][j] give the 2^j-th parent of i if exist or -1 if not

void dfs(int n){
    for(int elem:adj[n]){//elem is son of n
        if(depth[elem]!=-1)continue;
        depth[elem]=depth[n]+1;
        parent[elem]=n;
        dfs(elem);
    }
}

int find_kth(int n,int k){
    for(int j=logg;j>=0;j--){
        if(k & (1<<j)){
            n=up[n][j];
        }
    }
    return n;
}

int LCA(int a,int b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    //a is always deeper
    int k =depth[a]-depth[b];
    a= find_kth(a,k);
    if(a==b)return a;
    //now they have same depth
    for(int j=logg;j>=0;j--){
        if(up[a][j] != up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    //now we are sure they have same parent
    return parent[a];
}

int main(){
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //we give root depth 0 and parent -1
    int root =1;
    depth[root]=0;parent[root]=-1;
    dfs(root);

    for(int i=1;i<=n;i++){
        cout<<"here is i depth parent "<<i<<depth[i]<<parent[i]<<endl;
    }

    for(int i=1;i<=n;i++){
        up[i][0]=parent[i];
    }
    for(int j=1;j<=logg;j++){
        for(int i=1;i<=n;i++){
            if(up[i][j-1]==-1)continue;
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    //now we populated the up
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }

    return 0;
}
/*
7 6 3
1 2
1 3
2 4
2 5
3 6
3 7
6 7
6 2
5 2
 */