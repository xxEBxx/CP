
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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        set<ll> s;
        unordered_map<ll,ll> freq;
        for (ll i = 0; i < n; i++) {
            ll val;
            cin>>val;
            s.insert(val);
            freq[val]++;
        }
        vi f,arr;

        for (auto elem : s) {
            arr.push_back(elem);
            f.push_back(freq[elem]);
        }
        sort(all(f));
        reverse(all(f));

        ll res=0;
        for (ll i=0;i<arr.size();i++) {
            res += f[i]*arr[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
