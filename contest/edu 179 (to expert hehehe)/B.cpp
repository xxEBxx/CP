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
    ll fib[11];
    fib[1]=1;
    fib[2]=2;
    for(ll i=3;i<11;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        //vector<ll> arr(n);
        for(ll i=0;i<k;i++){
            vi a(3);
            cin>>a[0]>>a[1]>>a[2];
            ll sum = fib[n] + fib[n-1];
            sort(all(a));
            if(fib[n]<=a[0] && fib[n]<=a[1] && sum <= a[2])
                cout<<1;
            else
                cout<<0;

        }
        cout<<endl;
    }
    return 0;
}