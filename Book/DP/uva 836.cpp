#include <bits/stdc++.h>

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

int solve(vvi matrix) {
    int n1 = matrix.size(), n2 = matrix[0].size();
    vvi dp(n1 + 1, vi(n2 + 1, 0)); // Adjusted the size to fit the actual matrix dimensions
    int res = 0;

    // Compute prefix sums
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
        }
    }

    // Find the maximum size submatrix with all 1s
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            for (int ii = i; ii <= n1; ii++) {
                for (int jj = j; jj <= n2; jj++) {
                    int area = (ii - i + 1) * (jj - j + 1);
                    int val = dp[ii][jj]
                              - dp[ii][j - 1] - dp[i - 1][jj]
                              + dp[i - 1][j - 1];
                    if (area == val) {
                        res = max(res, area);
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    fast();
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore(); // Ignore the blank line after the number of test cases

    bool first = true;
    while (t--) {
        if (!first) cout << endl; // Print blank line between test case results
        first = false;

        string line;
        vector<vector<int>> matrix;

        while (getline(cin, line) && line.empty()) {} // Ignore the blank line before each test case

        do {
            vector<int> row;
            for (char c : line) {
                row.push_back(c - '0');
            }
            matrix.push_back(row);
        } while (getline(cin, line) && !line.empty());

        cout << solve(matrix) << endl;
    }

    return 0;
}
