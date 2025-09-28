#include <bits/stdc++.h>
using namespace std;

struct Stat {                // helper for “best so far”
    int zeros;               // how many zero factors
    long double lg;          // sum of logs (only if zeros == 0)
    int idx;                 // deletion index that produced it
};

bool better(const Stat& a, const Stat& b) {          // comparison rule
    if (a.zeros != b.zeros)           return a.zeros < b.zeros;
    if (a.zeros > 0)                  return a.idx   < b.idx;     // both 0 product
    if (fabsl(a.lg - b.lg) > 1e-12L)  return a.lg    > b.lg;
    return a.idx < b.idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n + 2, 0);              // 1-indexed, sentinels at ends
    for (int i = 1; i <= n; ++i) cin >> a[i];

    /* special case n = 2: just compare the two single-element beauties */
    if (n == 2) {
        cout << (a[1] >= a[2] ? 2 : 1) << '\n';
        return 0;
    }

    /* build xor-pairs */
    int m = n / 2;                              // floor
    vector<long long> px(m + 1);                // pairXor[1 … m]
    for (int j = 1; j <= m; ++j)
        px[j] = a[2*j - 1] ^ a[2*j];

    /* prefix stats */
    vector<int>       preZ(m + 1);
    vector<long double> preL(m + 1);
    for (int j = 1; j <= m; ++j) {
        preZ[j] = preZ[j-1];
        preL[j] = preL[j-1];
        if (px[j] == 0) ++preZ[j];
        else            preL[j] += log((long double)px[j]);
    }

    /* suffix stats */
    vector<int>       sufZ(m + 2);
    vector<long double> sufL(m + 2);
    for (int j = m; j >= 1; --j) {
        sufZ[j] = sufZ[j+1];
        sufL[j] = sufL[j+1];
        if (px[j] == 0) ++sufZ[j];
        else            sufL[j] += log((long double)px[j]);
    }

    Stat best{INT_MAX, -1e300L, 1};             // “worst” sentinel

    auto addFactor = [](long long val, int &z, long double &lg) {
        if (val == 0) ++z;
        else          lg += log((long double)val);
    };

    bool origOdd = (n & 1);
    long long tailOrig = origOdd ? a[n] : 0;    // tail when n is odd

    for (int i = 1; i <= n; ++i) {

        int z = 0;            long double lg = 0.0L;

        /* pairs fully on the left of i */
        int fullLeft = (i - 1) / 2;             // #complete pairs before i
        z  += preZ[fullLeft];
        lg += preL[fullLeft];

        /* pairs fully on the right of i */
        int firstRight = fullLeft + 1;          // index of pair that starts at 2*firstRight-1
        if (!(i & 1)) ++firstRight;             // skip the pair that begins with i-1 if i deletes its 2-nd element
        if (firstRight <= m) {
            z  += sufZ[firstRight];
            lg += sufL[firstRight];
        }

        /* crossing pair (only if i is even inside its pair) */
        if ((i & 1) == 0) {                     // second element of its pair
            long long val = a[i-1] ^ a[i+1];
            addFactor(val, z, lg);
        }

        /* tail element after deletion */
        if (!origOdd) {                         // original n was even → new length is odd
            long long tail;
            if (i == n)           tail = a[n-1];
            else                  tail = a[n];
            addFactor(tail, z, lg);
        } else {
            /* original n was odd – keep tail unless we delete it */
            if (i != n) addFactor(tailOrig, z, lg);
        }

        Stat candidate{z, lg, i};
        if (better(candidate, best)) best = candidate;
    }

    cout << best.idx << '\n';
    return 0;
}
