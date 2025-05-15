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
vi primes(maxn),jawab(maxn,0);
void estrathose(){
    for(ll i=1;i<maxn;i++){
        for(ll j=i;j<maxn;j+=i){
            if(primes[i]<=2)primes[j]++;
        }
    }
    for(ll i=1;i<maxn;i++){
        for(ll j=i;j<maxn;j+=i){
            if(j==i)continue;
            jawab[j] += ((1<<(primes[j/i-1]-1))+1)/2;
        }
    }

}

int main(){fast();
    ll t;cin>>t;
    estrathose();
    while(t--){
        ll n;cin>>n;
        cout<<jawab[n]<<endl;

    }
    return 0;
}