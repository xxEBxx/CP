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
        ll n;cin>>n;
        vector<ll> arr(n+1),ps(n+1,0);
        for(ll i=1;i<n+1;i++){
            cin>>arr[i];
            ps[i] = arr[i]+ps[i-1];
        }
        ll res=0ll;
        for(ll i =1;i<=n;i++){
            res += arr[i]*(ps[n]-ps[i]);
        }
        cout<<res<<endl;
    return 0;
}