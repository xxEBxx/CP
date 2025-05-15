//dijsktra between a and b unwighted
//we find the path and instead of printing it we see what was the move
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e3+3;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;
vector<ii> adj[maxn][maxn];
const int inf=1e7;

int main(){
    int n,m;cin>>n>>m;
    int xa,xb,ya,yb;
    vector<string> v(n);
    for(int i=0;i<n;i++){
            cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A'){
                xa=i;ya=j;
            }
            if(v[i][j]=='B'){
                xb=i;yb=j;
            }
            if(v[i][j] != '#'){
                if(i<n-1 && v[i+1][j]!='#'){
                    adj[i][j].push_back({i+1,j});
                    adj[i+1][j].push_back({i,j});

                    //cout<<"added to down in "<<i<<" "<<j<<" "<< adj[i][j][adj[i][j].size()-1].first <<" "<<adj[i][j][adj[i][j].size()-1].second<<endl;
                }
                if(j<m-1 && v[i][j+1]!='#'){
                    adj[i][j].push_back({i,j+1});
                    adj[i][j+1].push_back({i,j});
                    //cout<<"added to right in "<<i<<" "<<j<<" "<< adj[i][j][adj[i][j].size()-1].first <<" "<<adj[i][j][adj[i][j].size()-1].second<<endl;
                }
            }
        }
    }

    vector<vector<int>> dis(n,vector<int> (m,inf));
    vector<vector<ii>> parent(n,vector<ii> (m,{-1,-1}));

    set<iii> heap;
    heap.insert({0,{xa,ya}});
    dis[xa][ya]=0;
    while(!heap.empty()){
        int i=(*heap.begin()).second.first,j=(*heap.begin()).second.second;
        heap.erase(heap.begin());
        //if(i==xb && j==yb)break;
        for(auto elem : adj[i][j]){
            int i1=elem.first,j1=elem.second;
            if(dis[i][j] + 1 < dis[i1][j1]){
                heap.erase({dis[i1][j1],{i1,j1}});
                dis[i1][j1] = 1 + dis[i][j];
                parent[i1][j1]={i,j};
                heap.insert({dis[i1][j1],{i1,j1}});
            }
        }
    }
    ii index={xb,yb};
    vector<ii> path={};
    while(true){
        //cout<<" here is index "<<index.first<<" "<<index.second<<" "<<dis[index.first][index.second]<<endl;
        if((index.first==-1 && index.second==-1) || (index.second==ya && index.first==xa)){
            break;
        }
        path.push_back({index.first,index.second});
        ii par=parent[index.first][index.second];
        index={par.first,par.second};
    }
    if(index.first==-1 && index.second==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    //for(int )
    path.push_back({xa,ya});
    cout<<"YES"<<endl<<path.size()-1<<endl;
    for(int i=path.size()-1;i>0;i--){
        if(path[i].first > path[i-1].first)         cout<<'U';
        else if(path[i].first < path[i-1].first)    cout<<'D';
        else if (path[i].second < path[i-1].second) cout<<'R';
        else if (path[i].second > path[i-1].second) cout<<'L';
    }
    //for(int i=ln)

}