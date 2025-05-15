#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull MAX_A = 10000;  // Maximum value for elements in array a
vector<vector<ull>> prime_factors(MAX_A + 1);

// Function to precompute prime factors using Sieve of Eratosthenes
void sieve_of_eratosthenes() {
    for (ull i = 2; i <= MAX_A; ++i) {
        if (prime_factors[i].empty()) { // i is a prime number
            for (ull multiple = i; multiple <= MAX_A; multiple += i) {
                prime_factors[multiple].push_back(i);
            }
        }
    }
}

ull get_min_prime_factor(ull num) {
    if (num == 1) return 0; // 1 has no prime factors
    return prime_factors[num].empty() ? 0 : prime_factors[num][0];
}

ull get_sum_prime_factor(ull num) {
    if (num == 1) return 0; // 1 has no prime factors
    ull res=0;
    for (auto elem:prime_factors[num]) {
        ull repeat=0;
        while(num%elem==0){
            repeat++;
            num/=elem;
        }
        res+=elem*repeat;
    }
    return res;
}

void build(const vector<ull>& data, ull node, ull start, ull end) {
    if (start == end) {
        tree[node] = get_sum_prime_factor(data[start]);
    } else {
        ull mid = (start + end) / 2;
        build(data, 2 * node + 1, start, mid);
        build(data, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

class SegmentTree {
private:
    vector<ull> tree;
    ull n;

    ull get_min_prime_factor(ull num) {
        if (num == 1) return 0; // 1 has no prime factors
        return prime_factors[num].empty() ? 0 : prime_factors[num][0];
    }

    ull get_sum_prime_factor(ull num) {
        if (num == 1) return 0; // 1 has no prime factors
        ull res=0;
        for (auto elem:prime_factors[num]) {
            ull repeat=0;
            while(num%elem==0){
                repeat++;
                num/=elem;
            }
            res+=elem*repeat;
        }
        return res;
    }

    void build(const vector<ull>& data, ull node, ull start, ull end) {
        if (start == end) {
            tree[node] = get_sum_prime_factor(data[start]);
        } else {
            ull mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(ull idx, ull value, ull node, ull start, ull end) {
        if (start == end) {
            tree[node] = get_min_prime_factor(value);
        } else {
            ull mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(idx, value, 2 * node + 1, start, mid);
            } else {
                update(idx, value, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    ull query(ull l, ull r, ull node, ull start, ull end) {
        if (r < start || end < l) return 0; // Out of range
        if (l <= start && end <= r) return tree[node]; // Current segment is fully within range
        ull mid = (start + end) / 2;
        ull left_sum = query(l, r, 2 * node + 1, start, mid);
        ull right_sum = query(l, r, 2 * node + 2, mid + 1, end);
        return left_sum + right_sum;
    }

public:
    SegmentTree(const vector<ull>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    void update(ull idx, ull value) {
        update(idx, value, 0, 0, n - 1);
    }

    ull query(ull l, ull r) {
        return query(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_of_eratosthenes();

    ull n;
    cin >> n;
    vector<ull> a(n);

    for (ull i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ull q;
    cin >> q;

    SegmentTree seg_tree(a);
    vector<ull> results;

    for (ull i = 0; i < q; ++i) {
        ull type;
        cin >> type;
        if (type == 1) { // Remove a prime factor
            ull idx;
            cin >> idx;
            idx--; // Convert to 0-based index
            if (a[idx] > 1) {
                // Remove the last prime factor for simplicity
                ull prime_factor = prime_factors[a[idx]].back();
                a[idx] /= prime_factor;  // Update the value
                seg_tree.update(idx, a[idx]); // Update segment tree
            }
        } else if (type == 2) { // Query the sum of minimum prime factors
            ull l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-based index
            results.push_back(seg_tree.query(l, r));
        } else if (type == 3) { // Assign new value
            ull l, r, x;
            cin >> l >> r >> x;
            for (ull j = l - 1; j < r; j++) { // Convert to 0-based index
                a[j] = x;
                seg_tree.update(j, x); // Update segment tree
            }
        }
    }

    // Print results for all type 2 operations
    for (ull res : results) {
        cout << res << '\n';
    }

    return 0;
}