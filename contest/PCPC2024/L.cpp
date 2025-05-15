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
        ll n;cin>>n;
        ll x;cin >> x;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(all(arr));
        ll res = 0;
        for(ll i =n-1;i>=0;i--){
            ll index = lower_bound(arr.begin(),arr.end(),arr[i]-x) - arr.begin();
            res += (i - index)*(i - index- 1)/2;
        }
        cout << res;

    return 0;
}