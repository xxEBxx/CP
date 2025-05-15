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
    int n,m;
    cin>>n >> m;
    vector<vector<int>> g(n+1);
    vi degree(n + 1,0);
    for(int i=1,a,b;i<=m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        degree[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    vi topo;
    for(int i=1;i<=n;i++){
        if(degree[i] == 0)q.push(i);
    }
    int count = 0;

    while(!q.empty()){
        int front = q.top();

        count++;
        q.pop();
        degree[front]--;
        topo.push_back(front);
        for(int c:g[front]){
            degree[c]--;
            if(degree[c] == 0)q.push(c);
        }
    }

    if(count == n){
        for(int i: topo)cout << i << " ";

    }
    else{
        cout << "IMPOSSIBLE";
    }





    return 0;
}