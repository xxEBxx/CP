
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
    while (t--) {
        ll r,ss,x;
        cin >> r >> ss >> x;
        ll num = (x*ss*ss)/(r*r);
        if (num % 10 == 0) {
            if ((x*ss*ss) % (r*r) != 0)
                num++;
        }
        while (num%10 != 0 ) num++;
        cout << num << endl;
    }
    return 0;
}
