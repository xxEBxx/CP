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

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll arr[maxn];
map<ll,vector<ll>> g;

ll dfs(ll i){
    if(g[i].empty())return arr[i];
    ll res=(ll)1e18;
    for(ll child:g[i]){
        res=min(res,dfs(child));
    }
    if(res < arr[i])return res;
    else return (res+arr[i])/2 ;
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        g.clear();
        ll n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        for(int i=2;i <= n;i++){
            ll parent;cin>>parent;
            g[parent].push_back(i);
        }
        if(g[1].empty())cout<<arr[1]<<endl;
        else{
            ll res=(ll)1e18;
            for(ll child:g[1]){
                res=min(res,dfs(child));
            }
            cout<<arr[1]+res<<endl;
        }

    }
    return 0;
}

