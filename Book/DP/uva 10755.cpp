#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvi;

const ll maxn = 21;
const ll mod = (ll)1e9 + 7;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll a, b, c;
ll dp[maxn][maxn][maxn];

ll solve(const vector<vector<vector<ll>>> &arr) {
    // Initialize dp array to 0
    memset(dp, 0, sizeof(dp));

    // Fill dp array
    for (ll i = 1; i <= a; i++) {
        for (ll j = 1; j <= b; j++) {
            for (ll k = 1; k <= c; k++) {
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1]
                              - dp[i-1][j-1][k] - dp[i-1][j][k-1] - dp[i][j-1][k-1]
                              + dp[i-1][j-1][k-1]
                              + arr[i][j][k];
            }
        }
    }

    ll max_val = INT_MIN;

    // Find the maximum sub-cuboid sum
    for (ll i = 1; i <= a; i++) {
        for (ll j = 1; j <= b; j++) {
            for (ll k = 1; k <= c; k++) {
                for (ll ii = i; ii <= a; ii++) {
                    for (ll jj = j; jj <= b; jj++) {
                        for (ll kk = k; kk <= c; kk++) {
                            ll current_sum = dp[ii][jj][kk]
                                              - dp[i-1][jj][kk] - dp[ii][j-1][kk] - dp[ii][jj][k-1]
                                              + dp[i-1][j-1][kk] + dp[i-1][jj][k-1] + dp[ii][j-1][k-1]
                                              - dp[i-1][j-1][k-1];
                            max_val = max(max_val, current_sum);
                        }
                    }
                }
            }
        }
    }

    return max_val;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        vector<vector<vector<ll>>> arr(a + 1, vvi(b + 1, vi(c + 1, 0)));
        for (ll i = 1; i <= a; i++) {
            for (ll j = 1; j <= b; j++) {
                for (ll k = 1; k <= c; k++) {
                    cin >> arr[i][j][k];
                }
            }
        }
        cout << solve(arr) << endl;
        if(t>0)cout<<endl;
    }
    return 0;
}
