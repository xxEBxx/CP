#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}



const int maxn=(int)2*1e5+7;
const int mod=(int)998244353;

ll ppp(ll a,ll b){
    ll res = 1;
    ll pp = a;
    while(b>0){
        if(b&1){
            res *=pp;
            res%=mod;
        }
        pp*=pp;
        pp%=mod;
        b/=2;
    }
    return res;
}

int main(){fast();
        ll n,m;cin>>n>>m;
        ll res=0;
        if(m<2){
            cout<<0<<endl;
            return 0;
        }

        for(ll i=n-1;i>=1;i--){
            res += i*i * (n-i) * ppp(i+1,m-2);
            res%=mod;
            cout<<res<<endl;
        }
        cout<<(res*12882ll)%mod<<endl;

    return 0;
}