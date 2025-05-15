#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e4*3+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll a,b,c,d;
ll f(ll x){
    return a*x*x*x+b*x*x+c*x+d;
}
int main(){fast();
    vector<vi> estratos(maxn);
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            estratos[j].push_back(i);
            estratos[j].push_back(-i);
        }
    }
    //for( auto elem : estratos[96])cout<<elem<<" ";
    ll t;cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(d==0){
            cout<<"Yes"<<endl;
            cout<<0<<endl;
            continue;
        }
        ll res=-1e10;
        //for( auto elem : estratos[96])cout<<elem<<" ";
        for(auto elem:estratos[(int)abs(d)]){
            if(f((ll)elem)==0){
                res=elem;
                break;
            }
        }
        if(res<-1e9){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
            cout<<res<<endl;
        }

    }
    return 0;
}