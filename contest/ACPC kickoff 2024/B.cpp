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

        ll res = 1e18;
        ll y = (ll) sqrt(n) + 1;
        for(ll x =0 ; x*x <= n;x++){
            while(x*x + y*y > n){
                y--;
            }
            res = min(res, n-x*x - y*y);
            y++;
            res = min(res,x*x + y*y - n);
        }
        cout<<res<<endl;

    }
    return 0;
}