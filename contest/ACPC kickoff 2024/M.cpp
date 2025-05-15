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
        ll n;cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(all(arr));
        arr.erase(unique(all(arr)),arr.end());
        n=(int)arr.size();
        //for(auto elem : arr)cout<<elem<<endl;

        vi diff(n-1);
        if(n==1){
            cout<<2<<endl;
            continue;
        }

        for(ll i=0;i<n-1;i++){
            diff[i] = arr[i+1]-arr[i];
        }
        ll res = diff[0];
        for(ll i=1;i<n-1;i++){
            res = gcd(res,diff[i]);
        }
        if(res==1){
            cout<<-1<<endl;
            continue;
        }
        ll ans=-1;
        for(ll i=2;i*i<=res;i++){
            if(res%i == 0 ) {
                ans = i;
                break;
            }
        }
        if(ans == -1) {
            cout << res << endl;
        }
        else
            cout<<ans<<endl;

    }
    return 0;
}