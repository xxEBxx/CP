
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

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int main() {
    fast();
    int t;
    cin >> t;
    int dp[8] = {1,0,0,1,0,1,1,0};
    while (t--) {
        int n;
        cin >> n;
        int res = (n/8)*4;
        int cst = (n/8)*8+1;
        for (int i =cst ; i<=n ; i++) {
            res += dp[i-cst];
        }
        cout<<res<<endl;
    }
    return 0;
}
