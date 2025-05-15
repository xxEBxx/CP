//this is implementation of number of components
#include<bits/stdc++.h>

using namespace std;
const int maxn=2*1e5+7;
vector<int> adj[maxn];
vector<bool> visited(maxn,false);

void dfs(int i){
    visited[i]=true;
    for(int k : adj[i]){
        if(!visited[k])dfs(k);
    }
}

int main(){
    int n,m;cin>>n>>m;
    //we have elements from ,1 to n inclusive
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count =0;
    vector<int> representative;
    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            dfs(i);
            count++;
            representative.push_back(i);
        }
    }
    cout<<count-1<<endl;
    for(int i=0;i<representative.size()-1;i++){
        cout<<representative[i]<<" "<<representative[i+1]<<endl;
    }

}