#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Define ordered_set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Read salaries
    vector<int> salaries(n);
    for (int i = 0; i < n; ++i) {
        cin >> salaries[i];
    }

    // Initialize ordered_set with salaries
    ordered_set<pair<int, int>> salarySet; // Use pair to handle duplicates
    unordered_map<int, int> empToSalary;
    for (int i = 0; i < n; ++i) {
        salarySet.insert({salaries[i], i}); // Use index as a unique identifier
        empToSalary[i + 1] = salaries[i];
    }

    // Process queries
    while (q--) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            // Update salary
            int oldSalary = empToSalary[k];
            salarySet.erase({oldSalary, k - 1}); // Remove old salary
            salarySet.insert({x, k - 1}); // Insert new salary
            empToSalary[k] = x; // Update map
        } else {
            int a, b;
            cin >> a >> b;
            // Range query using order_of_key
            int count = salarySet.order_of_key({b + 1, 0}) - salarySet.order_of_key({a, 0});
            cout << count << "\n";
        }
    }

    return 0;
}
