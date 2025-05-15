#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int max_b = 1000;

vector<int> precompute_steps() {
    vector<int> steps(max_b + 1, INF);
    steps[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int x = 1; x <= a; ++x) {
            int m = a / x;
            int next_a = a + m;
            if (next_a > max_b) continue;
            if (steps[next_a] > steps[a] + 1) {
                steps[next_a] = steps[a] + 1;
                q.push(next_a);
            }
        }
    }
    return steps;
}

vector<int> steps = precompute_steps();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        int sum_initial = 0;
        vector<pair<int, int>> items;
        for (int i = 0; i < n; ++i) {
            int required = steps[b[i]];
            items.emplace_back(required, c[i]);
        }

        vector<int> dp(k + 1, 0);
        for (auto &item : items) {
            int cost = item.first;
            int value = item.second;
            for (int j = k; j >= cost; --j) {
                //this is an amount of money
                dp[j] = max(dp[j],dp[j - cost] + value);
            }
        }

        int max_coins = sum_initial + *max_element(dp.begin(), dp.end());

        cout << max_coins << '\n';
    }

    return 0;
}