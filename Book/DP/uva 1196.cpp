#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define f first
#define s second

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
    cin.tie(0);
    cout.tie(0);
}

struct elem {
    int l, m;
    bool operator<(const elem& other) const {
        if (l != other.l) return l < other.l;
        return m < other.m;
    }
};

int main() {
    fast();
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<elem> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].l >> arr[i].m;
        }

        sort(all(arr));

        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i].m >= arr[j].m) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = *max_element(all(dp));
        cout << res << endl;
    }
    cout << "*";
    return 0;
}
