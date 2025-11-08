#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e7 + 5;
const int mod = (int) 1e9 + 7;
vector<int> spf(maxn,-1);

void pre() {
    for (ll i=2;i<maxn;i++) {
        if (spf[i] != -1)continue;
        for (int j = i;j<maxn;j+=i) {
            if (spf[j] == -1)spf[j] = i;
        }
    }
}


int main() {
    pre();
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll p;
        cin >> n >> p;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(all(arr));
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= p) {
                res++;
                p = p + spf[arr[i]];
            }
        }
        cout << res << " " << p << endl;
    }
    return 0;
}

