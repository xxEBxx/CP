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
        ll n,total;
        cin>>n;
        vector<ll> arr(n);
        total=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            total+=arr[i];
        }
        if(n<=2){
            cout<<-1<<endl;
            continue;
        }
        sort(all(arr));
        ll res = (2*arr[n/2])*n-total+1;
        cout<<max(res,(ll)0)<<endl;

    }
    return 0;
}