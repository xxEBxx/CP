#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

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
    cout.tie(0);
    cin.tie(0);
}

struct obj {
    int l, r, index;
};

int b;

bool comp(obj x, obj y) {
    if (x.l / b == y.l / b)
        return x.r < y.r;
    return x.l / b < y.l / b;
}


int main() {
    fast();
    int n, m;
    cin >> n >> m;
    b = max(1, (int)sqrt(n)); // Ensure block size is at least 1
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //JUST COMPRESSING THE ELEMENTS
    vi arrcopy=arr;
    sort(all(arrcopy));
    unordered_map<int,int> compress;
    for(int i=1;i<=n;i++){
        compress[arrcopy[i]]=i;
    }
    for(int i=0;i<n;i++){
        arr[i]=compress[arr[i]];
    }

    //Order of QUERIESS
    vector<obj> queries(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1, i};
    }
    sort(all(queries), comp);

    // Mo's algorithm
    vi freq(maxn, 0);
    vi res(m);
    int i = 0, j = -1;
    int distinct = 0;
    for (auto& elem : queries) {
        int l = elem.l, r = elem.r;

        while (j < r) {
            j++;
            freq[arr[j]]++;
            if (freq[arr[j]] == 1) distinct++;
        }

        while (i > l) {
            i--;
            freq[arr[i]]++;
            if (freq[arr[i]] == 1) distinct++;
        }

        while (j > r) {
            freq[arr[j]]--;
            if (freq[arr[j]] == 0) distinct--;
            j--;
        }

        while (i < l) {
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) distinct--;
            i++;
        }
        res[elem.index] = distinct;
    }

    for (int x : res) {
        cout << x << "\n";
    }
    return 0;
}