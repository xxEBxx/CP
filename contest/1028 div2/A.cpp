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

const ll maxn=(ll)1e5+7;
const ll mod = 998244353;

int main(){fast();
    ll p2[maxn] ;
    p2[0]=1;
    for(ll i=1;i<maxn;i++){
        p2[i] = 2*p2[i-1];
        p2[i] %= mod;
    }
    //for(int i=0;i<100;i++)cout<<p2[i]<<" ";
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vi p(n),q(n);
        for(ll i=0;i<n;i++)cin>>p[i];
        for(ll i=0;i<n;i++)cin>>q[i];

        ll index1=0,index2=0,val1=0,val2=0;

        for(ll i=0;i<n;i++){

            if(p[i] >= val1 ){
                index1 = i;
                val1=p[i];
            }

            if(q[i] >= val2){
                index2 = i;
                val2=q[i];
            }

            ll res2 = (p2[p[i-index2]] + p2[q[index2]])%mod;
            ll res1 = (p2[p[index1]] + p2[q[i-index1]])%mod;
            if( val1 > val2 || (val1==val2 && q[i-index1] > p[i-index2])){
                cout<<res1<<" ";
            }
            else
                cout<<res2<<" ";
        }
        cout<<endl;

    }
    return 0;
}