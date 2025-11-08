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
    cin >> n>>k;
    vi arr(n+1,0),carr(n+1,0);
    for (ll i = 1; i < 1+n; i++) {
        cin >> arr[i];
    }
    ll d=0;
    for (ll i=1;i<=n;i++) {
        if (arr[i] <= arr[i-1])
            d++;
        carr[i] =arr[i]+ d*24;
    }

    ll res=0;
    for (ll i=k+1;i<=n;i++) {
        res = max(res,carr[i]-carr[i-k-1]);
    }
    cout<<res-1<<endl;

    return 0;
}
