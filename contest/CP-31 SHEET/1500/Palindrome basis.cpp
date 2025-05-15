#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 4e4 + 7;

vector<int> generatePalindromes(int maxN) {
    vector<int> palindromes;
    for (int i = 1; i <= maxN; ++i) {
        string s = to_string(i);
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        if (s == reversed_s) {
            palindromes.push_back(i);
        }
    }
    return palindromes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    // Precompute all palindromic numbers up to 4e4
    vector<int> palindromes = generatePalindromes(MAX_N);

    // Precompute the number of ways using dynamic programming
    vector<int> dp(MAX_N + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0 (using no numbers)

    for (int p : palindromes) {
        for (int i = p; i <= MAX_N; ++i) {
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}