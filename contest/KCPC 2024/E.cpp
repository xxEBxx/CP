#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 1e7 + 2;
const ll mod = (ll) 1e9 + 7;



int main() {
    fast();
    vi facto(maxn);
    facto[0]=1;
    for (ll i=1 ; i<maxn ; i++) {
        facto[i] = i*facto[i-1];
        facto[i] %= mod;
    }


    long long  t;
    cin >> t;
    while (t--) {
        long long  n,k;
        cin >> n>>k;
        if (k==1) {
            cout<<facto[n]<<endl;
            continue;
        }
        long long  res = facto[n-2];
        res*=2;res%=mod;
        long long  a = (((k-1)*(n-k))%mod + ((k-1)*k/2 ) %mod)%mod;
        cout<<(res*a)%mod<<endl;
    }
    return 0;
}
