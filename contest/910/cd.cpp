
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
        ll n;
        cin >> n;
        vi arr(n);
        for (ll i = 0; i < n; i++) {
            cin>>arr[i];
        }
        sort(all(arr));
        vector<ii> p;
        for (ll i =0;i<n;) {
            ll cnt=1;
            ll j =i+1;
            while (arr[i]==arr[j]) {
                cnt++;
                j++;
            }
            p.push_back({arr[i], cnt});
            i=j;
        }

        n = p.size();
        ll base=0;
        vi rest;
        for (ll i=0;i<n;i++) {
            base += p[i].f/2 * p[i].s;
            if (p[i].f&1)
                rest.push_back(p[i].s);
        }
        sort(all(rest));
        reverse(all(rest));
        ll p1=base,p2=base;
        for (ll i =0;i<rest.size();i++) {
            if (i&1)p2+=rest[i];
            else p1+=rest[i];
        }
        cout<<p1<<" "<<p2<<endl;
    }
    return 0;
}
