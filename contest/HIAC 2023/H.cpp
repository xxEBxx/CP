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

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n+1,0),before(n+1,0),after(n+1,0);
        ll max_elem=0;
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
            max_elem=max(max_elem,arr[i]);
        }
        for(ll i=1;i<=n;i++){
            before[i]=i-1;
            after[i]=i+1;
        }
        ll q;cin>>q;
        cout<<max_elem<<endl;
        for(ll j=0;j<q;j++){
            ll index;cin>>index;
            after[before[index]]=after[index];
            before[after[index]]=before[index];
            arr[after[index]]+=arr[index];
            max_elem=max(max_elem,arr[after[index]]);
            cout<<max_elem<<endl;
            arr[index]=0;
        }
    }
    return 0;
}