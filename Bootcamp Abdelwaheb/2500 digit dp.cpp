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

string a,b;
int n,dp[19][1<<21][2][2];

int solve(int i,int bitmask,int big_a,int small_b) {
    if (i==n) {
        int div = 0;
    }
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        cin>>a>>b;
        while (a.size()<b.size()) {
            a = '0'+a;
        }
        memset(dp,-1,sizeof(dp));

    }
    return 0;
}
