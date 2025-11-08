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

vi arr;
vector<set<ll>> s1(4),s2(4);
ll n,s;

int main() {
    fast();
    cin>>n>>s;
    for (ll i=0;i<n;i++) {
        ll val;cin>>val;
        arr.push_back(val);
    }

    s1[0].insert(0);
    for (ll i=0;i<n/2;i++) {
        vector<set<ll>> nxt = s1;
        if (arr[i] < 0) {
            for (ll j=0;j<3;j++) {
                for (auto elem : s1[j])
                    nxt[j + 1].insert(arr[i] + elem);
            }
        }
        else {
            for (ll j=0;j<4;j++) {
                for (auto elem : s1[j])
                    nxt[0].insert(arr[i] + elem);
            }
        }
        s1 = nxt;
    }

    s2[0].insert(0);
    for (ll i=n-1;i>=n/2;i--) {
        vector<set<ll>> nxt = s2;
        if (arr[i] < 0) {
            for (ll j=0;j<3;j++) {
                for (auto elem : s2[j])
                    nxt[j + 1].insert(arr[i] + elem);
            }
        }
        else {
            for (ll j=0;j<4;j++) {
                for (auto elem : s2[j])
                    nxt[0].insert(arr[i] + elem);
            }
        }
        s2 = nxt;
    }

    bool ans=false;
    ll res = 1e18;
    for (ll z=0;z<4;z++) {
        //we will only look at oz <= 3-z
        for (auto base : s1[z]) {
            //we want s-base <= other and other be minimal
            for (ll oz=0;oz+z <= 3;oz++) {
                if (s2[oz].empty() || *s2[oz].rbegin() < s-base)continue;
                ll other = *s2[oz].lower_bound(s-base);
                res = min(res,other +base);
                ans=true;
            }
        }
    }
    if (!ans) {
        cout<<"Impossible"<<endl;
    }
    else {
        cout<<res<<endl;
    }


    return 0;
}
