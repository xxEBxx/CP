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

int  main(){fast();
    ll x;cin>>x;
    vi res;
    for(ll h=1;h <= (ll)1e5;h++){
        ll y2=h*h+x;
        ll y=(ll)sqrt(y2);
        if( y*y == y2 && y>h){
            res.push_back(y);
        }
    }
    cout<<res.size()<<endl;

    for(ll i=0;i < res.size();i++) {
        if(i>0)cout<<" ";
        cout << res[i] ;
    }

    return 0;
}