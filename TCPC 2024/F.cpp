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


bool check(string s,ll k,ll speed) {
    ll cur = speed;
    for (int i=0;i<s.length();i++) {
        if (s[i] == '1' ) {
            if (cur > 10LL) {
                if (k == 0)
                    return false;
                k--;
            }
            cur = speed;
        }
        else
            cur  = max(cur - 10LL,10LL);
    }
    return  true;
}
int main() {
    fast();
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll a = 1,b = 1e17;
    while (b - a > 1LL) {
        ll c = (a+b)/2;
        bool tr = check(s,k,c*10LL);
        if (tr)
            a = c;
        else
            b = c-1;
    }
    if (check(s,k,b*10LL))
        cout << b*10LL;
    else
        cout << a*10LL;

    return 0;
}
