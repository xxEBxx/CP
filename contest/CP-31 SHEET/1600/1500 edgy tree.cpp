#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

vector<ll> parent, rank_;

void make_set(ll v) {
    parent[v] = v;
    rank_[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

ll ppp(ll a,ll i){
    ll dreb=a,res=1;
    while(i>0){
        if(i&1){
            res *= dreb;
            res %= mod;
        }
        i/=2;
        dreb*=dreb;
        dreb%=mod;
    }
    return res;
}

int main(){fast();
    ll n,k;cin>>n>>k;
    parent.resize(n+1);
    rank_.resize(n+1);
    for(ll i=1;i<n+1;i++){
        make_set(i);
    }

    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(c==0)
            union_sets(a,b);
    }
    unordered_map<ll,ll> m;
    for(ll i=1;i<=n;i++){
        m[find_set(i)]++;
    }
    //for(auto elem : m)cout<<elem.f<<" "<<elem.s<<endl;

//the idea is that we take n^k and for each set we need to remove size^k of that set
    ll res = ppp(n,k);
    vector<ll> visited_root(n+1,0);
    for(ll i=1;i<=n;i++){
        ll r = find_set(i);
        if(visited_root[r])continue;
        res -= ppp(m[r],k);
        while(res<0)res += mod;
        visited_root[r]=1;
    }

    cout<<res<<endl;
    return 0;
}