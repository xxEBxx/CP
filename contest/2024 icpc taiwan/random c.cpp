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
    ll t,tt=0;
    cin>>t;
    while(t--){tt++;
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        ll min_val=1e18;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            min_val=min(min_val,arr[i]);
        }
        cout<<"Case #"<<tt<<": ";
        if(n<3){
            if(min_val<=k)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            continue;
        }
        if(min_val * (2*n -3) <= k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}