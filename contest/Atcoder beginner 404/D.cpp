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
    ll n,m;cin>>n>>m;

    vi cost(n);
    for(ll i=0;i<n;i++)
        cin>>cost[i];

    vvi zoo(n);//there are n zoos and m animals
    for(ll i=0;i<m;i++){
        ll k;cin>>k;
        for(ll j=0;j<k;j++){
            ll val;
            cin>>val;val--;
            zoo[val].push_back(i);
        }
    }
    ll res = 1e18;
    ll maxState = 1;
    for(ll i=1;i<=n;i++)maxState*=3;
    //erach bit says did we visit this zoo 0 1 or 2 timews


    for(ll ii=0;ii < maxState;ii++){
        vi count(m,0);
        ll price=0ll;
        ll state =ii;
        for(ll i =0;i<n;i++){

            price += cost[i]*(state%3);
            if(price >= res)
                break;

            for(ll a : zoo[i]){
                count[a] += state%3;
            }
            state /= 3;
        }
        for(ll a :count ){
            if (a < 2){
                price = 1e18;
                break;
            }
        }

        res = min(res,price);
    }
    cout<<res<<endl;

    return 0;
}