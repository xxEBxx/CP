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
        ll n,m;
        cin >> n>>m;
        string s;
        cin>>s;

        map<ll,ll> exist;
        for (ll i=0;i<m;i++) {
            ll val;cin>>val;
            exist[val]=1;
        }
        ll x=1;
        for (ll i=0;i<n;i++) {
            if (s[i]=='A') {
                x++;
                exist[x]=1;
            }
            else {
                x++;
                while (exist[x]==1)x++;
                exist[x]=1;
                while (exist[x]==1)x++;
            }
        }
        int res=0;
        for (auto elem : exist) {
            if (elem.s==1)res++;
        }
        cout<<res<<endl;
        for (auto elem : exist) {
            if (elem.s==1)
                cout<<elem.f<<" ";
        }
        cout<<endl;
    }
    return 0;
}
