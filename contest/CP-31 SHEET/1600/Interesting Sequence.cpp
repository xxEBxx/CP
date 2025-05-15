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
const ll logg=64;
ll next_elem_0_position(ll num,ll pos){
    //search for first 0 after the pos
    ll i;
    ll res=0;
    for(i=pos+1;i<logg;i++){
        if( ((num>>i) & 1) == 0){
            res = (1LL<<i);
            break;
        }
    }
    i++;
    for(;i<logg;i++){
        if( (num>>i) & 1){
            res += (1LL<<i);
        }
    }
    return res;
}


int main(){fast();
    //cout<<next_elem_0_position(20ll,1)<<endl;
    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        ll lb=n,ub=(ll)5e18;
        ll res=1;
        for(ll i=0;i<logg;i++) {
            if ((n >> i) & 1 && (x >> i) & 1) {
                ub = min(ub, next_elem_0_position(n, i)-1);
            } else if ((n >> i) & 1 && ((x >> i) & 1) == 0) {
                lb = max(lb, next_elem_0_position(n, i));
            } else if ((x >> i) & 1 && ((n >> i) & 1) == 0) {
                res = -1;
            }
        }
        if(res==-1 || ub < lb)
            cout<<-1<<endl;
        else
            cout<<lb<<endl;
    }

    return 0;
}