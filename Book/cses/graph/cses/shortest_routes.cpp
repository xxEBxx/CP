#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int maxn=(int)1e5 +3;
const ll inf=(ll)1e14+7;
vector<ii> adj[maxn];

int main(){
    ll n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }

    set<ii> heap;
    //this will keep track of (distance from 1 , index)
    vector<ll> dis(n+1,inf);//p for parent aka path and
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
                heap.insert({dis[k],k});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;

}
