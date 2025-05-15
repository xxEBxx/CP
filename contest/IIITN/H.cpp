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
    ll n,k,t;cin>>n>>k>>t;

    vector<ll> arr(n+1,0);
    arr[n]=k;
    for(ll ii=0;ii < t/5;ii++){
        vector<ll> next(n+1,0);
        next[n]=arr[n];
        for(ll i=0;i<n;i++){
            next[i]=arr[i]+arr[i+1];
            next[i]%=mod;
        }
        arr=next;
    }
    cout<<arr[0]%mod<<endl;

    return 0;
}