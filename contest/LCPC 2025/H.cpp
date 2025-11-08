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
vector<long double> arr;
int n;
long double simulate(long double a) {
    long double res = 0;
    long double x = a;
    for (int i=0;i<n;i++) {
        res += arr[i] * ((long double)1/(long double)(i+1)) * x;
        x *= a;
    }
    return res;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        long double k;
        cin >> n >> k;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long double low = 0,high = k;
        while (high - low > 0.0000001) {
                long double c = (high + low)/2;
                if (simulate(c) >= k) {
                    high = c;
                }
                else {
                    low = c;
                }

        }
        printf("%.7f\n",(double)low);
    }
    return 0;
}
