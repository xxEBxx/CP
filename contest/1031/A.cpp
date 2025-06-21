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
        ll k,a,b,c,d;
        cin>>k>>a>>b>>c>>d;
        ll p1 = min(c,d),p2=c+d-p1;
        ll e1,e2;
        if (p1==c)e1=a;
        else e1=b;
        e2=a+b-e1;

        ll res=0 ;
        if (k>=e1) {
            res += (k-e1)/p1 + 1;
            k -= p1 * ((k-e1)/p1 + 1);
        }
        if (k>=e2) {
            res += (k-e2)/p2 + 1;
            k -= p2 * ((k-e2)/p2 + 1);
        }
        cout<<res<<endl;
    }
    return 0;
}
