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

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n,sum=0,min_elem=1e9+1;cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            min_elem=min(min_elem,arr[i]);
        }
        for(ll i=0;i<n;i++){
            if(arr[i]==min_elem)continue;
            sum -= arr[i]-1-min_elem;
        }
        cout<<sum<<endl;

    }
    return 0;
}