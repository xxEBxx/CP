#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const ll logg=19;
ll cyclelength;
ll cycleleader;



vector<ll> dsu, rankk,degree,parent;
vector<ll> depth,depth2,distances;
vector<vector<pair<ll,ll>>> g;
vector<vector<ll>> up;
//up[i][j] give the 2^j-th parent of i if exist or-1 if not


void dfs(ll n,ll root){
    for(auto elem:g[n]){
        //elem is son of n
        if(depth[elem.first]!=-1 || dsu[elem.first]<0)continue;
        depth[elem.first]=depth[n]+1;
        distances[elem.first] = distances[n] + elem.second;
        parent[elem.first]=n;
        dsu[elem.first] = root;
        dfs(elem.first,root);
    }
}

void dfs2(ll n){
    for(auto elem:g[n]){//elem is son of n
        if(elem.first == cycleleader)cyclelength = max(cyclelength,depth2[n] + elem.second);
        if(depth2[elem.first]!=-1 || dsu[elem.first]>0)continue;
        depth2[elem.first]=depth2[n]+elem.second;
        dfs2(elem.first);
    }
}

ll find_kth(ll n,ll k){
    for(ll j=logg;j>=0;j--){
        if(k & (1<<j)){
            n=up[n][j];
        }
    }
    return n;
}

ll LCA(ll a,ll b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    //a is always deeper
    ll k = depth[a]-depth[b];
    a=find_kth(a,k);
    if(a==b)return a;
    //nowtheyhavesamedepth
    for(ll j=logg;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    //nowwearesuretheyhavesameparent
    return parent[a];
}

void make_set(ll v) {
    dsu[v] = v;
    rankk[v] = 0;
}

ll find_set(ll v) {
    if (v == dsu[v])
        return v;
    return dsu[v] = find_set(dsu[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap(a, b);
        dsu[b] = a;
        if (rankk[a] == rankk[b])
            rankk[a]++;
    }
}


int main(){
    ll t;cin >> t;

    while(t--){
        ll n,q;cin >> n>> q;
        dsu.assign(n+1,0);
        cyclelength = (ll)0;
        depth2.assign(n+1,(ll)-1);
        distances.assign(n+1,(ll)0);
        degree.assign(n+1,0);
        parent.assign(n+1,0);
        depth.assign(n+1,(ll)-1);
        up.assign(n+1,vector<ll>(logg+1,-1));

        g.assign(n+1,vector<pair<ll,ll>>());
        rankk.resize(n+1,0);
        for(ll i=1;i<=n;i++){
            make_set(i);
        }
        // find the cycle
        ll c;
        for(ll i=0,a,b;i<n;i++){
            cin >> a>> b >> c;
            g[a].push_back({b,(ll)c});
            g[b].push_back({a,(ll)c});
            degree[a]++;
            degree[b]++;
        }
        queue<ll> que;
        for(ll i=1;i<=n;i++){
            if(degree[i]==1){
                que.push(i);
            }
        }
        while (!que.empty()){
            ll front = que.front();
            degree[front] = 0;
            que.pop();
            for(auto neighbour:g[front]){
                if(degree[neighbour.first]==0)continue;
                degree[neighbour.first]--;
                if(degree[neighbour.first]==1)que.push(neighbour.first);
            }
        }
        cycleleader = 1;
        for(ll i=1;i<=n;i++){
            if (degree[i]!= 0){
                dsu[i]=-i;
            }
        }
        //degree[i]==0 means that it's not in the cycle
        for(ll i=1;i<=n;i++){
            if (degree[i] != 0){
                cycleleader = i;
                dsu[i]=-i;
                distances[i] = 0;
                depth[i]=0;
                parent[i]=-1;
                dfs(i,i);
            }
        }
        depth2[cycleleader] = (ll)0;
        dfs2(cycleleader);
        for(ll i=1;i<=n;i++){
            up[i][0]=parent[i];
        }

        for(ll j=1;j<=logg;j++){
            for(ll i=1;i<=n;i++){
                if(up[i][j-1]==-1)continue;
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }

        for(ll qq=0,a,b;qq<q;qq++){
            scanf("%d %d",&a,&b);
            if (abs(dsu[a] )== abs(dsu[b])){
                ll p = LCA(a,b);
                cout << distances[a] + distances[b] - (ll)2 * distances[p]  << "\n";
            }
            else{
                ll res = max(depth2[abs(dsu[a])],depth2[abs(dsu[b])])-min(depth2[abs(dsu[a])],depth2[abs(dsu[b])]);
                cout << distances[a] + distances[b] + min(res,cyclelength - res)  << "\n";
                cout << "Query " << qq + 1 << ": (" << a << ", " << b << ")" << endl;
                cout << "Component A: " << dsu[a] << ", Component B: " << dsu[b] << endl;

            }

        }
    }
    return 0;
}
/*
1
10 100
1 2 2
1 3 4
2 6 3
3 4 1
3 5 10
3 6 6
5 7 4
5 8 4
2 9 3
2 10 2
 */