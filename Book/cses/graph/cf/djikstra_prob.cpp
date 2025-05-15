//link :https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int maxn=(int)1e5 +3;
const ll inf=(ll)1e11+7;
vector<ii> adj[maxn];

int main(){
    ll n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    set<ii> heap;
    //this will keep track of (distance from 1 , index)
    vector<ll> parent(n+1,-1),dis(n+1,inf);//p for parent aka path and
    heap.insert({0,1});//first element
    dis[1]=0;
    while(!heap.empty()){
        ll p=heap.begin()->second;
        //cout<<"here is elem "<< dis[p]<<" "<<p<<endl;
        heap.erase(heap.begin());

        for(auto elem : adj[p]){
            ll cost=elem.second , k=elem.first;
            if(dis[k] >= dis[p] + cost){
                heap.erase({dis[k],k});
                dis[k]=dis[p]+cost;
                parent[k]=p;
                heap.insert({dis[k],k});
            }
        }
    }

    ll index=n,count=0;
    vector<ll> path;

    while(count < n+2 && index != -1 && index != 1){
        count++;
        path.push_back(index);
        index=parent[index];
    }
    reverse(path.begin(),path.end());
    if(index != 1) cout<<-1;
    else{
        cout<<1<<" ";
        for(ll k:path)cout<<k<<" ";
    }
    return 0;

}


