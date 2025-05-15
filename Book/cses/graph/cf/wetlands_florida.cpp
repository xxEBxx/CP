#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int>> g[100][100];
int visited[100][100];

int solve(int i,int j){
    //given i and j find size of the component containing it;
    visited[i][j]=1;
    int res=0;
    for(pair elem: g[i][j]){
        if(!visited[elem.first][elem.second])res+=solve(elem.first,elem.second);
    }
    return 1+res;//itself plus all neighbours
}

int main(){
    int t;cin>>t;
    while(t--){
        //for each element from the grid , we will have a
        //full vector of it's connected elements
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                g[i][j].clear();
                visited[i][j]=0;
            }
        }
        vector<string> grid;
        string line ;
        while(true){
            cin>>line;
            if(isdigit(line[0]))break;
            grid.push_back(line);
        }
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(grid[i][j]=='W'){
                    if(grid[i-1][j]=='W') {
                        g[i][j].push_back({i - 1, j});
                        g[i-1][j].push_back({i, j});
                    }
                    if(grid[i][j-1]=='W'){
                        g[i][j-1].push_back({i, j});
                        g[i][j].push_back({i , j-1});
                    }
                    if(grid[i-1][j-1]=='W'){
                        g[i-1][j-1].push_back({i, j});
                        g[i][j].push_back({i-1 , j-1});
                    }
                }
            }
        }
        while(true){
            memset(visited,0,sizeof(visited));
            cout<<solve(line[0]-'0'-1,line[2]-1-'0');
            cin>>line;
            if(line.empty())break;
        }

    }
    return 0;
}