
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
    fast();string s;
    cin >> s;
    int n = s.size();
    bool tr = false;
    int i;
    for (i=0;i<n;i++) {
        if (s[i] == 'T') {
            tr = true;
            break;
        }
    }
    if (!tr) {
        cout << 'N';
        return  0 ;
    }
    tr = false;
    int j;
    for (j = i+1;j<n;j++) {
        if (s[j] == 'A') {
            tr = true;
            break;
        }
    }
    if (!tr) {
        cout << 'N';
        return  0 ;
    }
    tr = false;
    for (int k = j;k<n;k++) {
        if (s[k] == 'P') {
            tr = true;
            break;
        }
    }
    if (!tr) {
        cout << 'N';
        return  0;
    }
    cout << 'S';

    return 0;
}
