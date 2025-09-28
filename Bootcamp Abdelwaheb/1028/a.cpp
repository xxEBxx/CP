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
    int n;
    cin >> n;
    vi arr(n);
    int B = 21;

    int M = 1 << B;
    vector<int> f(M, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        f[arr[i]]++;
    }

    for (int j=0;j<B;j++) {
        for (int mask = M-1;mask >= 0;mask--) {
            if ((mask & (1<<j)) == 0) {
                f[mask] += f[mask | (1<<j)];
                f[mask]%=mod;
            }
        }
    }
    int p2[n+1];
    p2[0]=1;
    for (int i=1;i<=n;i++) {
        p2[i] = p2[i-1]*2;
        p2[i]%=mod;
    }
    //f contains the exact superset
    for (int mask =M-1;mask >= 0;mask--){
        f[mask] = (p2[f[mask]] + mod - 1) % mod;
    }

    //now we need to keep only the exact ones
    for (int j=0;j<B ;j++) {
        for (int mask =M-1;mask >= 0;mask--) {
            if ((mask & (1<<j)) == 0) {
                f[mask] = (f[mask]-f[mask | (1<<j)]+mod)%mod;

            }
        }
    }
        cout<<f[0]<<" ";

    return 0;
}
