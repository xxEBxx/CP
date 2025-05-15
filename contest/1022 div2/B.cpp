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
    ll t;cin>>t;
    while(t--){
        ll n,b;
        cin>>n>>b;
        if(b==0){
            if(n==1)cout<<-1<<endl;
            else if(n%2==0)cout<<n<<endl;
            else {
                cout<<n-3 + 6<<endl;
            }
            continue;
        }
        ll number = __builtin_popcount(b);
        if(n <= number){
            cout<<b<<endl;
            continue;
        }
        ll gen = n-number;
        if(gen&1)gen++;
        if(gen == n){
            ll j=0;
            while((b>>j)&1){
                j++;
            }
            cout<<b + (1<<(j+1)) + gen-2<<endl;
            continue;
        }
        cout<< b + gen<<endl;
    }
    return 0;
}