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
        bool eq=true;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(i>0 && arr[i]!=arr[i-1])eq=false;
        }
        if(eq){
            cout<<0<<endl;
            continue;
        }
        vi last(n);
        for(ll i=0;i<n;i++){
            ll j =i+1;
            while(j<n && arr[i]==arr[j]){
                j++;
            }
            for(ll k = i;k<j;k++){
                last[k]=j-1;
            }
            i=j-1;
        }
        ll res=1e18;
        for(ll i=0;i<n;i++){
            res = min(res, arr[i] * (i + n-last[i]-1));
        }
        cout<<res<<endl;
    }
    return 0;
}