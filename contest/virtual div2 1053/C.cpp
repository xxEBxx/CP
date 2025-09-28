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
        n += n;
        vi arr(n+1,0);
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (ll i=1;i<=n;i++) {
            if (i&1) {
                arr[i] = arr[i-1]-arr[i];
            }
            else {
                arr[i] = arr[i-1]+arr[i];
            }
        }

        ll total=arr[n];
        cout<<total<<" ";
        for (ll i=2;i<=n/2;i++) {
            ll loc = arr[n+1-i] - arr[i-1];
            if (i%2==0)total -= 2*loc;
            else total += 2*loc;
            cout<<total<<" ";
        }
        cout<<endl;

    }
    return 0;
}
