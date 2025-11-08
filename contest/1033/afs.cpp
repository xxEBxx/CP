
#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

#define all(v) v.begin(), v.end()
#define f first
#define s second


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
        cin >> n;
        vector<ii> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i].f;
            arr[i].f--;
        }
        for (ll i = 0; i < n; i++) {
            cin >> arr[i].s;
            arr[i].s--;
        }
        vector<ll> color(n,0);
    //for each color what is highest
        ll res=0;
        for (ll i=0;i<n;i++) {
            if (color[arr[i].s] > arr[i].f) {
                res += arr[i].s+1;
            }
            else {
                color[arr[i].s] = arr[i].f;
            }
        }
        cout<<res<<endl;

    return 0;
}
