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
        int n;
        cin >> n;
        int xk,yk,xd,yd;
        cin>>xk>>yk>>xd>>yd;

        int d;
        if (xk==xd) {
            if (yk < yd)
                d = yk+1;
            else
                d = n-yk+1;
        }
        else if (yk==yd) {
            if (xk < xd)
                d = xk+1;
            else
                d = n-xk+1;
        }
        else
            d = abs(xk-xd) + abs(yk-yd);
        cout<< d<<endl;
    }
    return 0;
}
