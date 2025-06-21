

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
        vi even,odd;
        ll s1=0,s2=0;
        for (ll i = 0; i < n; i++) {
            ll val;cin>>val;
            if (val&1){odd.push_back(val);s1+=val;}
            else {even.push_back(val);s2+=val;}
        }
        sort(all(even));
        sort(all(odd));
        if (even.empty() ) {
            cout<<odd[odd.size()-1]<<endl;
        }
        else if (odd.empty() ) {
                cout<<even[even.size()-1]<<endl;
        }
        else {
            cout<<s1+s2-odd.size()+1<<endl;
        }
    }
    return 0;
}
