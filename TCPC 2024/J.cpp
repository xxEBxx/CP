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
    ll a,b ,c;cin >> a >> b >> c;
    ll sq = -1;
    for (ll i = 1;i<= (ll)1e6+1;i++) {
        if (i*i == c) {
            sq = i;
            break;
        }
    }
    if (sq == -1) {
        for (ll i = 1;i<= (ll)1e6+1;i++) {
            if (i*i > c)break;
            ll temp = sqrt(c - i*i);
            if (temp * temp == c - i*i) {
                ll x = i + a;
                ll y = temp + b;
                cout << "YES"<<endl;
                cout << x << " " << y << endl;
                cout << (ll)2*a - x << " " << 2*b -y << endl;
                cout << (ll)2*a - x << " " << y << endl;
                return 0;
            }
        }



        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << a - sq << " " << b << endl;
    cout << a + sq << " " << b << endl;
    cout <<  a << " " << b + sq << endl;
    return 0;
}
