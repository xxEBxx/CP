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
    ll n,k;
    cin>>n>>k;
    n %= mod;
    ll res = 1;
    for(ll i=0;i<k;i++){
        res *= n;
        res %= mod;
    }


    vi arr(k);
    for(ll i=0;i<k;i++)cin>>arr[i];

    if(n == 1){
        cout << k<<endl;
        return 0;
    }


    ll i=0;

    while(i<k && arr[i]==arr[0]){
        i++;
    }
    //cout<<i<<endl;
    cout<<(res + n * (ll)(i>1) % mod) % mod<<endl;

    return 0;
}