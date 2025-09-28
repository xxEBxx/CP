
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
    cin>>n>>k;
    ll m =10;
    vi weight(m);
    for (ll i=0;i<m;i++) {
        cin>>weight[i];
    }
    vi score(n,0);
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<m;j++) {
            ll val;cin>>val;
            score[i] += weight[j]*val;
        }
    }
    sort(all(score));
    reverse(all(score));
    ll res=0;
    for (ll i=0;i<k;i++)
        res += score[i];
    cout<<res<<endl;
    return 0;
}
