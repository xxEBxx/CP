#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int c = min(k, m - 1);
        int rem = (m - 1) - c;
        int res = 0;
        for (int x = 0; x <= c; x++) {
            int worst = INT_MAX;
            for (int a = 0; a <= rem; a++) {
                int s = x + a;
                int e = (n - m) + x + a;
                worst = min(worst, max(arr[s], arr[e]));
            }
            res = max(res, worst);
        }
        cout << res << endl;
    }
    return 0;
}