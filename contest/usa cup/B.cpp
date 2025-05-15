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
        vector<ll> a(n),b(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
        ll res=min(b[n-1],a[n-1]);

        for(ll i=n-2;i>=0;i--){
            res=min(a[i] + 2*res , b[i]+res);
        }

        cout<<res;
    return 0;
}