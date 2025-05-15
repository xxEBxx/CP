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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    ll b1=0,b2=0;

    if(arr[0] > 0)b1=arr[0];

    for(ll i=1;i<n;i++){
        if(arr[i]<0 && b1 + arr[i] > b2)
            b2 = b1 + arr[i];
        if(arr[i]>0 && b2 + arr[i] > b1)
            b1 = b2 +arr[i];
    }
    cout<<max(b1,b2)<<endl;

    return 0;
}