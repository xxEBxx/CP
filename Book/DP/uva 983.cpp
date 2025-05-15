#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn = (int)1e6 + 7;
const int mod = (int)1e9 + 7;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    fast();
    string line;bool start=true;int m,n;
    while (cin>>n) {
        cin>>m;
        if(!start)cout<<endl;
        else start=false;

        vector<vector<int>> arr(n + 1, vi(n + 1, 0)), dp(n + 1, vi(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> arr[i][j];
                dp[i][j] = arr[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }

        int res = 0;
        for (int i = 1; i <= n - m + 1; ++i) {
            for (int j = 1; j <= n - m + 1; ++j) {
                int sum = dp[i + m - 1][j + m - 1] - dp[i + m - 1][j - 1] - dp[i - 1][j + m - 1] + dp[i - 1][j - 1];
                cout << sum << endl;
                res += sum;
            }
        }
        cout << res<<endl;
        //cin.ignore();
    }
    return 0;
}
