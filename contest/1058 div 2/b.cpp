
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
            cin >> arr[i];
        }
        vi ans(n);
        ll curr_diff=2;
        ans[0]=1;
        for (ll i=1;i<n;i++) {
            ll diff = arr[i]-arr[i-1];
            if (diff <= i) {
                ans[i] = ans[i-diff];
            }
            else {
                ans[i] = curr_diff;
                curr_diff++;
            }
        }
        for (auto elem : ans) {
            cout<<elem<<" ";
        }
        cout<<endl;
    }
    return 0;
}
