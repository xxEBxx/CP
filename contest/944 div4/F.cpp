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
        ll res=0;
        ll n;cin>>n;
        for(ll i=1;i<=n;i++){
            ll y=(ll)sqrt((n+1)*(n+1)-i*i);
            while(y*y+i*i >= (n+1)*(n+1)){
                y--;
            }
            while(y*y+i*i >= n*n && y>=0){
                y--;
                res++;
            }
        }
        cout<<res*4<<endl;
    }
    return 0;
}