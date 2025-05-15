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

ll dist_7(ll x){
    if(x>=7)return x-7;
    return x+3;
}
ll dist_1(ll x){
    if(x==0)return 9;
    return x-1;
}

ll solve(ll n,ll index){
    //0 indexed
    //there are 2 ways
    ll way1 = (ll)pow(10,index)-1;
    ll iteration=0,res=-1;
    while(true){
        ll n_inside = n + iteration*way1;
        while(n_inside>0){
            if(n_inside%10 == 7){
                res=iteration;
                break;
            }
            n_inside/=10;
        }
        if(res>-1)break;
        iteration++;
    }
    return res;
}

int main(){fast();
    ll t;cin>>t;

    while(t--){
        ll n;cin>>n;

        ll res=10;
        for(ll i=1;i<11;i++){
            res=min(res,solve(n,i));
        }
        cout<<res<<endl;
    }
    return 0;
}