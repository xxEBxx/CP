#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair< ll,  ll> ii;
typedef vector< ll> vi;

const  ll maxn = 1501;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    fast();
    ll ps[maxn][maxn] = {0};
    ll res[maxn * maxn] = {0};
    res[0] = 0;
     ll curr = 1;
    for ( ll iteration = 1; iteration < maxn; iteration++) {
        for ( ll j = 0; j < iteration && curr < maxn * maxn; j++) {
             ll x = iteration - j;//between 1 and maxn-1
             ll y = j + 1;//between 1 and maxn-2
                ps[x][y] = ps[x][y - 1] + ps[x - 1][y] - ps[x - 1][y - 1] + curr * curr;
                res[curr] = ps[x][y];
            curr++;
        }
    }

     ll t;
    cin >> t;
    while (t--) {
         ll n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}
