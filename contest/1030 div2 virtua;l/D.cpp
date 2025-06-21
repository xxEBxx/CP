#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; int64 k;
        cin >> n >> k;
        vector<int64> p(n), d(n);
        for (auto &x : p) cin >> x;
        for (auto &x : d) cin >> x;

        /* --- build buckets by id = (d - p) mod k ----------------------- */
        unordered_map<int64, vector<int64>> bucket;
        bucket.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            int64 id = ( (d[i] - p[i]) % k + k ) % k;   // always 0 … k-1
            bucket[id].push_back(p[i]);
        }
        for (auto &kv : bucket)  // sort each bucket once
            sort(kv.second.begin(), kv.second.end());

        /* ----------------------- answer queries ------------------------ */
        int q;  cin >> q;
        while (q--) {
            int64 a; cin >> a;
            int64 need = ( (-a) % k + k ) % k;          // (3)

            auto itB = bucket.find(need);
            if (itB == bucket.end() || itB->second.size() <= 1) {
                cout << "YES\n";
                continue;
            }
            const auto &v = itB->second;
            auto it = lower_bound(v.begin(), v.end(), a);

            bool has_right = (it != v.end());           // ≥ a
            bool has_left  = (it != v.begin());         // <  a

            cout << (has_left && has_right ? "NO\n" : "YES\n");
        }
    }
    return 0;
}
