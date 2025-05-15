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

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;
int n;

vvi divisors(maxn);

void estrathos(){
    for(int i=2;i<maxn;i++){
        for(int j=i+i;j<maxn;j+=i){
            if(divisors[i].empty())
                divisors[j].push_back(i);
        }
    }
}
unordered_map<int,vi> g(maxn);

vi visited(maxn,0);
void dfs(int node){
    visited[node]=1;
    for(int next : g[node]){
        if(visited[next]==1)continue;
        dfs(next);
    }
}

int main(){fast();
    estrathos();
    cin>>n;
    vi arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int div : divisors[arr[i]]){
            //cout<<arr[i]<<" "<<div<<endl;
            g[div].push_back(arr[i]);
            g[arr[i]].push_back(div);
        }
    }
    dfs(arr[0]);
    string res="yes";
    for(int elem:arr){
        if(visited[elem]==0) {
            res = "no";
            break;
        }
    }
    cout<<res<<endl;

    return 0;
}