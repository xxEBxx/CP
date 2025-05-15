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
        vector<ll> arr(n);
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        ll res=sum;
        while(arr.size()>1){
            vi next_arr;
            ll next_sum=0;
            for(ll i=0;i<arr.size()-1;i++){
                next_arr.push_back(arr[i+1]-arr[i]);
                next_sum += arr[i+1]-arr[i];
            }
            arr = next_arr;
            res = max(res,abs(next_sum));
        }

        cout<<res<<endl;

    }
    return 0;
}