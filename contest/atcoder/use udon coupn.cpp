//https://atcoder.jp/contests/arc204/tasks/arc204_a

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

const int maxn = 5002;
const int mod = (int) 1e9 + 7;

int n,l,r,dp[maxn][maxn];

int solve(int i,int j) {
    if (i==n && j==n) {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];


}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    return 0;
}
