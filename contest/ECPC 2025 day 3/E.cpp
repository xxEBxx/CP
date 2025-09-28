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

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n,val;
        cin >> n>>val;

        ll bit =0;
        while ((1LL<<bit) <= val) {
            bit++;
        }
        bit--;

        //bit is msb
        // is sequence starting with bit valid ?
        ll seq = (1LL<<bit);
        for (ll i = bit-2;i>=0;i-=2)
            seq |= (1LL<<i);
        if (seq > val)
            bit--;
        if (n <= bit)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
