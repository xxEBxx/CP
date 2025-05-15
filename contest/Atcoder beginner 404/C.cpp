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

int main(){fast();
    int n,m;cin>>n>>m;
    vvi g(n+1);vi visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(g[i].size()!=2){
            cout<<"No"<<endl;
            return 0;
        }
    }

    queue<int> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        int head = q.front();
        visited[head]=1;
        q.pop();
        for(auto c : g[head]){
            if(visited[c])continue;
            q.push(c);
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i] ==0 ){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}