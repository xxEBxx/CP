
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

struct node {
    ll l,r,i;
};

bool comp1(node a,node b) {
    if (a.l != b.l)return a.l<b.l;
    return a.r < b.r;
}

bool comp2(node a,node b) {
    if (a.r != b.r)return a.r<b.r;
    return a.l < b.l;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<node> arr(n);
        ll res=0;
        vector<ii> sum(n);
        ll ans=0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i].l>>arr[i].r;
            sum[i] = {arr[i].l+arr[i].r,i};
            res += arr[i].r - arr[i].l;
            ans += arr[i].r;
        }
        sort(all(sum));
        for (ll i=0;i<n/2;i++) {
            //we change ans by removing r and l to have halve r and half left
            ans -= sum[i].f;
        }
        for (ll i=0;i<n;i++) {
            if (n&1 && sum[i].s == n/2)ans -= arr[i].r - arr[i].l;
        }
        cout<<ans+res<<endl;


    }
    return 0;
}
