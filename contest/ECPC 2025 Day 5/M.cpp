
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
        ll x,k;
        cin>>x>>k;
        ll n = x/(k+1);
        ll c2 = (k+1)*(n+1)-x;

        ll c1=(x-c2*k)/(k+1);
        if (c1<0 || c2<0)
            cout<<-1<<" "<<-1<<endl;
        else
            cout<<c1<<" "<<c2<<endl;
    }
    return 0;
}
