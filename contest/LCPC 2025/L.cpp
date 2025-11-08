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
bool op(pair<ll,ll>a,pair<ll,ll> b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}
int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll q,m;
        cin >> q >> m;
        vector<pair<ll,ll>> arr;
        for (ll i=0;i<q;i++) {
            string s;
            cin >> s;
            ll dur;
            cin >> dur;
            string hour = s.substr(0,2);
            ll h = stoi(hour)*60;
            string mi = s.substr(3,2);
            h += stoi(mi);
            if (h+dur-1 <= 1440)
                arr.push_back({h,dur});
        }
        sort(arr.begin(),arr.end(),op);
        multiset<ll> ss;
        ll free = m;
        ll time = 0;
        bool tr = true;
        for (pair<ll,ll> pp : arr) {
            time = pp.first;
            if (free > 0) {
                ll add = time + pp.second-1;
                ss.insert(add);
                free--;
            }
            else {
                if (*ss.begin() >= time ) {
                    tr = false;
                    break;
                }
                ss.erase(ss.begin());
                ss.insert(time+pp.second-1);
            }
        }
        if (tr)
            cout << "YES" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
