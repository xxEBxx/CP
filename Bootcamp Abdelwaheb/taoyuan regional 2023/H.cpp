#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;                            // knapsack capacity
    cin >> C;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   // flush end-of-line

    // read values (second line)
    string line;
    getline(cin, line);
    istringstream iss_val(line);
    vector<int> val;
    for (int x; iss_val >> x;) val.push_back(x);

    // read weights/prices (third line)
    getline(cin, line);
    istringstream iss_w(line);
    vector<int> w;
    for (int x; iss_w >> x;) w.push_back(x);

    int n = (int)val.size();          // assumes val.size() == w.size()
    vector<int> dp(C + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int cap = C; cap >= w[i]; --cap) {
            dp[cap] = max(dp[cap], dp[cap - w[i]] + val[i]);
        }
    }
    cout << dp[C] << '\n';
}
