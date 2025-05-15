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

const int maxn=3*(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

map<ll,vector<ll>> g;
vector<ll> size_of(maxn,0),arr(maxn,0);

ll find_size(ll i){
    ll res=1;
    for(ll elem: g[i]){
        res += find_size(elem);
    }
    return size_of[i]=res ;
}

int main(){fast();
    ll n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        ll parent;
        cin >> parent;
        g[parent].push_back(i);
    }
    find_size(1);
    //for(int i=1;i<=n;i++)cout<<size_of[i]<<" ";cout<<endl;
    ll res=0;
    for(int i=2;i<=n;i++){
        res += size_of[i]* (size_of[1]-size_of[i]);
    }
    cout<<res<<endl;
    return 0;
}