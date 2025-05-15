
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxn=1e3+7;
vector<ii> adj[maxn][maxn];
vector<vector<bool>> visited(maxn,vector<bool> (maxn,false));

void dfs(int i,int j){
    //cout<<"here is i j "<<i<<" "<<j<<endl;
    visited[i][j]=true;
    for(auto elem : adj[i][j]){
        if(!visited[elem.first][elem.second])dfs(elem.first,elem.second);
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'){
                if(i<n-1 && v[i+1][j]=='.'){
                    adj[i][j].push_back({i+1,j});
                    adj[i+1][j].push_back({i,j});
                }
                if (j<m-1 && v[i][j+1]=='.'){
                    adj[i][j].push_back({i,j+1});
                    adj[i][j+1].push_back({i,j});
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<"here is i j"<<i<<" "<<j<<v[i][j]<<" "<<visited[i][j]<<" "<<endl;

            if(v[i][j]=='.' && !visited[i][j]){
                dfs(i,j);
                count++;
                //cout<<" count added"<<count<<endl;
            }
        }
    }
    cout<<count;
}
