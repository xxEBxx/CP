#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

int main() {
    fast();
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i=0;i<n;i++)
        cin >> arr[i];

    ll am = arr[k-1];

    arr[k-1] = 0;
    ll add = (am/n);
    for (ll i=0;i<n;i++) {
        arr[i] += add;
    }
    am%=n;
    ll i = k%n;
    while (am>0) {
        arr[i]++;
        am--;
        i++;
        i%=n;
    }

    for (auto elem : arr)cout << elem << " ";

    return 0;
}
