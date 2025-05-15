#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

#define ll long long
using namespace std;
const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;


vector<int> parent(maxn,0);
vector<int> depth(maxn,-1);
vector<vector<int>> adj(maxn);
const int logg=19;
vector<vector<int>> up(maxn,vector<int>(logg,-1));

void dfs(int n){
    for(int elem:adj[n]){//elemissonofn
        if(depth[elem]!=-1)continue;
        depth[elem]=depth[n]+1;
        parent[elem]=n;
        dfs(elem);
    }
}

int find_kth(int n,int k){
    for(int j=logg;j>=0;j--){
        if(k&(1<<j)){
            n=up[n][j];
        }
    }
    return n;
}

int lca(int a,int b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }

    int k = depth[a]-depth[b];
    a=find_kth(a,k);
    if(a==b)return a;


    for(int j=logg;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];

        }
    }


    return parent[a];
}


int main(){
    ifstream cin("awesome.in");
    int t;
    cin >> t;

    while(t--){
        parent.assign(maxn,0);
        depth.assign(maxn,-1);
        adj.assign(maxn,vector<int>());
        up.assign(maxn,vector<int>(logg,-1));

        int n,l,r; cin >> n >> l >> r;


        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int root=1;
        depth[root]=0;parent[root]=-1;
        dfs(root);


        for(int i=1;i<=n;i++){
            up[i][0]=parent[i];
        }

        for(int j=1;j<=logg;j++){
            for(int i=1;i<=n;i++){
                if(up[i][j-1]==-1)continue;
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }


        ll res = 0;

        for(int i=1;i<=n;i++){
            for(int p=i+1;p<=n;p++){


                int aaa = lca(i,p);
                ll dis = n - 1 - (abs(depth[aaa] - depth[i]) + abs(depth[aaa] - depth[p]));

                if ((aaa == i || aaa == p) && abs(depth[p] - depth[i])==1)continue;
                else if( l <= dis && dis <= r)res++;



            }

        }
        cout << res << "\n";


    }
    return 0;
}