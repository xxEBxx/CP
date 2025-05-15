#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+3;
unordered_map<int,int> parent;
vector<int> adj[maxn+1];
vector<bool> visited_parent(maxn,false);
vector<bool> visited(maxn,false);

void find_childs(int k){
    visited_parent[k]=true;
    for(int i:adj[k]){
        if(!visited_parent[i]){
            parent[i] = k;
            find_childs(i);
        }
    }
}

int main(){
    int logn=21;
    int t;cin>>t;
    while(t--){
        parent.clear();
        for(int i=0;i<maxn;i++){
            adj[i].clear();
            visited[i]=false;
            visited_parent[i]=false;
        }

        int n,m;cin>>n>>m;
        for(int i=1;i<n;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        find_childs(1);
        /*for(auto elem :parent){
            cout<<elem.first<<" "<<elem.second<<endl;
        }*/
        vector<vector<int>> down(maxn,vector<int> (logn,-1));
        for(int i=0;i<=n;i++){
            down[i][0]=parent[i];
        }
        for(int j=1;j<logn+1;j++){
            for(int v=2;v<=n;v++){
                if(down[v][j-1]==-1) {
                    continue;
                     }
                down[v][j]=down[down[v][j-1]][j-1];

            }
        }
        //we need to binary search to find the element that is not taken yet for each query
        //aka we need to find lowest element that is not visited yet
        int node;cin>>node;
        cout<<1<<" ";
        visited[1]=true;
        for(int i=0;i<m-1;i++){
            cin>>node;
            //cout<<"initial node : "<<node<<endl;
            if(visited[node]){
                cout<<-1<<" ";
                continue;
            }
            //nb9a ntl3 7ta nl9a bah tchaf
            int index=16;
            while(!visited[parent[node]]){
                //cout<<"here is the node "<<node<<endl;
                //can i go deep 2^index time
                if(down[node][index]!=-1 && !visited[down[node][index]]){
                    node=down[node][index];
                }
                index--;
            }
            visited[node]=true;
            cout<<node<<" ";
        }
        cout<<endl;
    }
}