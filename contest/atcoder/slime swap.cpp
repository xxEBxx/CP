//https://atcoder.jp/contests/arc206/tasks/arc206_b

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

ll lis(vi arr) {
    ll n=arr.size();
    vi L(n+2, 0), L_id(n+2, 0),p(n+2,-1);
    ll k = 0, lis_end = 0;
    for (ll i = 0; i < n; i++) {
        //cout<<"here is arr[i]"<<arr[i]<<endl;
        ll pos = lower_bound(L.begin(), L.begin()+k, arr[i]) - L.begin();
        //cout<<"here is pos"<<pos<<" "<<L.size()-1<<" "<<k<<endl;
        L[pos] = arr[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if (pos == k ) {
            k = pos+1;
            lis_end = i;
        }
        else if (pos==k-1)lis_end=i;
    }
    return k;
}

int main() {
    fast();
        ll n;
        cin >> n;
        vector<ii> arr(n+1);
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i].f;
        }
        vvi color(n+1);

        for (ll i = 1;i <= n;i++) {
            cin>>arr[i].s;
            color[arr[i].s].push_back(arr[i].f);
        }

    ll res=0;
    for (ll i=1;i<=n;i++) {
        res += (color[i].size() - lis(color[i])) * i;
    }
    cout<<res<<endl;



    return 0;
}
