#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(v) v.begin(), v.end()
#define f first
#define s second


typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.f > b.f;
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<pair<ll,ll>> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i].f>>arr[i].s;
        }
        sort(all(arr),comp);
        ordered_set<ll> a;
        ll res=0;
        for(ll i=0;i<n;i++){
            a.insert(arr[i].s);
            ll index=a.order_of_key(arr[i].s);
            res+=index;
        }
        
        cout<<res<<endl;

    }
    return 0;
}