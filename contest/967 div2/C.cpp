#include<bits/stdc++.h>
#include <utility>    // for pair

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1001;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int req(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 2; i <= n; i++) {
        int t = 1;
        while (true) {
            int x = req(t, i);
            if (t == x) break;
            t = x;
        }
        ans.push_back({i, t});
    }
    cout << "! ";
    for (auto [a, b]: ans) {
        cout << a << ' ' << b << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}