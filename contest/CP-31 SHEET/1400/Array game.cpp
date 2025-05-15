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
        ll n,k;cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        sort(all(arr));
        vi next_arr;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                next_arr.push_back(abs(arr[i]-arr[j]));
            }
        }
        sort(all(next_arr));
        ll min_element = min(next_arr[0],arr[0]);
        if(min_element==0 || k==1){
            cout<<min_element<<endl;
            continue;
        }

        for(int i=0;i<next_arr.size();i++){
            int index = lower_bound(all(arr),next_arr[i])-arr.begin();
            min_element=min(min_element,arr[index]-next_arr[i]);
            if(index>0)min_element=min(min_element,abs(arr[index-1]-next_arr[i]));
        }
        cout<<min_element<<endl;

    }
    return 0;
}