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
    int n = 6;
    vector<pair<ll,ll>> arr(n);
    for (int i=0;i<n;i++)
        cin >> arr[i].first >> arr[i].second;
    ll mmin = 1e9 + 7 , mmin2 = 1e9 + 7;
    for (int i=0;i<n;i++) {
        mmin = min(arr[i].first,mmin);
        mmin2 = min(mmin2,arr[i].second);
    }
    ll out = 0;
    for (int i=0;i<n;i++) {
        out += (arr[i].first - mmin);
        out += (arr[i].second - mmin2);
    }
    cout << out;

    return 0;
}
