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
const ll mod=(ll)998244353;


int main(){fast();
    vi facto(1e6+1);
    facto[1]=1;
    for(ll i=2;i<1e6+1;i++){
        facto[i] = facto[i-1] * i;
        facto[i] %= mod;
    }
    int MAXN =1e6;
    vector<ll> D(MAXN+1, 0);
    D[0] = 1;
    if(MAXN >= 1) D[1] = 0;
    for(int i = 2; i <= MAXN; i++){
        D[i] = (ll)(i - 1) * (D[i-1] + D[i-2]) % mod;
    }
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n==1)
            cout<<0<<endl;
        else if(n%2==0)
            cout<<1<<endl;
        else{
            cout<<(facto[n]*D[n])%mod<<endl;
        }
    }
    return 0;
}