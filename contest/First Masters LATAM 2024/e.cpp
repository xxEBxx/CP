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

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}



int main(){fast();
    int n,m,k,temp1,temp2;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    vector<int> parent;
    vector<int> height(n + 1,-1);
    vector<int> degree(n + 1,0);
    vector<int> vis(n + 1,0);
    vector<int> children;

    for(int i=0;i<m;i++){
        cin >> temp1;
        cin >> temp2;
        g[temp1].push_back(temp2);
        g[temp2].push_back(temp1);
    }

    for(int i=0;i<k;i++){
        cin >> temp1;
        parent.push_back(temp1);
        vis[temp1] = 1;
        height[temp1] = 0;
    }

    while(parent.size() != 0){
        for(int p:parent){
            for(int child:g[p]){
                if(!vis[child]){
                    degree[child]++;
                    if(degree[child] >= 2){
                        children.push_back(child);
                        height[child] = 1 + height[p];
                        vis[child] = 1;

                    }
                }
            }


        }

        parent = children;
        children.clear();
    }

    cout << height[1];
    return 0;
}