// https://codeforces.com/contest/321/problem/E

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
const int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const double EPS = 1e-7;
const int mod = 1e9+7; // 1e9+7, 998244353
// BEFORE coding are you sure you understood the statement correctly?
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.

const int N = 4e3+10, K = 808;
int mat[N][N], dp[K][N];

int C(int i, int j) {
    return (mat[j][j]-mat[i-1][j]-mat[j][i-1]+mat[i-1][i-1])/2;
}

void compute(int k, int l, int r, int optl, int optr) {
    if (r < l) return;
    int mi = (l+r)/2;
    int opt = -1;
    for (int i = optl; i <= min(mi, optr); i++) {
        if (dp[k][mi] > dp[k-1][i-1]+C(i, mi)) {
            dp[k][mi] = dp[k-1][i-1]+C(i, mi);
            opt = i;
        }
    }
    compute(k, l, mi-1, optl, opt);
    compute(k, mi+1, r, opt, optr);
}

void burn(int tc)
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            mat[i][j]+=mat[i][j-1];
        }
        for (int j = 1; j <= n; j++) {
            mat[i][j]+=mat[i-1][j];
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        compute(i, 1, n, 1, n);
    }
    cout << dp[k][n];
}

int main()
{
    AboTaha_on_da_code

    // freopen("A2in.txt", "r", stdin);
    // freopen("A2out.txt", "w", stdout);

    int T = 1; // cin >> T;

    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << i << ": ";
        burn(i);
        cout << '\n';
    }
    return 0;
}