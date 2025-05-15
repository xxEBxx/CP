#include<bits/stdc++.h>

using namespace std;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        unordered_map<int, vector<int>> indexes;
        for (int i = 0; i < n; i++) {
            indexes[arr[i]].push_back(i + 1);
        }
        vector<int> last_one(n + 2, 1e9); // Initialize to handle up to d = n
        for (auto &p : indexes) {
            int x = p.first;
            vector<int> &v = p.second;
            int m = v.size();
            int d = max(v[0], n + 1 - v.back());
            for (int j = 0; j < m - 1; j++) {
                d = max(d, v[j + 1] - v[j]);
            }
            if (d <= n) { // Ensure we don't exceed the bounds of last_one
                if (x < last_one[d]) {
                    last_one[d] = x;
                }
            }
        }
        int res = 1e9;
        for (int k = 1; k <= n; k++) {
            res = min(res, last_one[k]);
            if (res == 1e9) {
                cout << -1 << " ";
            } else {
                cout << res << " ";
            }
        }
        cout << endl;
    }
    return 0;
}