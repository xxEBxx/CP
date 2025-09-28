
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
ll n,m,l;
ll fto(ll i,ll j) {
    if (j>=i)return j-i;
    return j+m-i;
}
int main() {
    fast();
    cin>>n>>m>>l;
    vi arr(n+1,0);

    for (ll i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i] += arr[i - 1];
        arr[i] %= m;

    }

    ll res=0;
    //i is the one we will change to make first part 0
    for (ll i=0;i<1;i++) {
        vi all;
        for (ll j = 0; j <= n; j += l) {
            all.push_back(arr[j]);
        }
        ll ans = 1e9;
        for (ll select: {0}) {
            ll loc = 0;
            for (ll elem: all) {
                loc += fto(elem, select);
            }
            ans = min(ans, loc);
        }
        res += ans;
    }
    for (ll i=1;i<l;i++) {
        //i is the one we will change to make first part 0
        vi all;
        for (ll j=i;j<=n;j+=l) {
            all.push_back(arr[j]);
        }
        ll ans=1e9;
        for (ll select :all) {
            ll loc=0;
            for (ll elem : all) {
                loc += fto(elem,select);
            }
            ans = min(ans,loc);
        }
        res+=ans;
    }
    cout<<res<<endl;
    return 0;
}
