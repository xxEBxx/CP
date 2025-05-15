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
        ll n,k;cin>>n>>k;
        ll dec=1;
        while(k > dec*(dec-1)/2){
            dec++;
        }
        k -= dec*(dec-1)/2;
        k *= -1;

        vi res(n+1);
        for(ll i=1;i <= n-dec;i++){
            res[i]=i;
        }
        for(ll i=n-dec+1;i<=n;i++){
            res[i] = n-i+(n-dec+1);
        }
        for(ll i= n-dec+k;i>=n-dec+1;i--){
            swap(res[i],res[i+1]);
        }
        for (ll i = 1; i <= n; i++)cout << res[i] << " ";
        cout << endl;

    }
    return 0;
}