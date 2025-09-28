
#include<bits/stdc++.h>

// Library effective with Linux
#include <unistd.h>

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

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

int main() {
    fast();
    ll n;
    cin>>n;

    if (n<9) {
        cout<<n;
    }
    else if (n%2==0) {
        cout<<(n/2)%mod;
    }
    else if (n<20) {
        if (n<14)cout<<4;
        else if (n<16)cout<<6;
        else if (n<18)cout<<8;
        else cout<<9;
    }
    else {
        cout<<max(4ll,1ll+(n-11)/2)%mod;
    }

    return 0;
}
