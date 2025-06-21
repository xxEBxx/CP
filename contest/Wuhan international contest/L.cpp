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
        vi arr(n+1,0);
        map<ll,ll> start,end;
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sort(all(arr));
        for (ll i=1;i<=n;i++) {
            if (start[arr[i]] == 0)start[arr[i]] = i;
            end[arr[i]] = i;
        }

        ll res=1;
        for (ll i=1;i<=n;i++) {
            for (ll j=i+1;j<=n;j++) {
                if ((arr[i]+arr[j]) & 1)continue;
                ll median = *lower_bound(all(arr),(arr[i]+arr[j])/2);

                if (median != (arr[i]+arr[j])/2 || start[median] == 0)continue;
                ll middle = (i+j )/2 ;
                ll diff=0 ;
                if (middle < start[median] ) {
                    diff = start[median] - middle+1;
                }
                else if (middle > end[median]) {
                    diff = middle - end[median] +1;
                }
                res = max(res,j-i-diff+1);
            }
        }
        cout<<res<<endl;

    }
    return 0;
}
