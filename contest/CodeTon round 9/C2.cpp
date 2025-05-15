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
        ll x,m;cin>>x>>m;
        ll res=0;
        for(ll y=1;y<=m;y++){
            int num=x^y;
            if(num%x==0 || num%y==0){
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}