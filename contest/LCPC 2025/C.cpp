#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll res  = 0 ;
        for (ll i=0;i<n;i++) {
            cin >> arr[i];
            res += min(arr[i]%k,(k - arr[i]%k));
        }
        cout << res << endl;


    }


    return 0;
}
