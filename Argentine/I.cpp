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
    ll n,m;
    cin>>n>>m;
    vi scores(n+1,0);
    for (ll ii=0;ii<m;ii++) {
        ll x,y;
        cin>>x>>y;
        ll k =0;
        vi choice(n+1,0);
        for (ll j=1;j<=n;j++) {
            cin>>choice[j];
            if (choice[j]==1) {
                k++;
            }
            else {
                scores[j] += y;
            }
        }
        ll add =0;
        if (y > x/(k+1)) {//ines either takes y or x/(k+1)
            scores[0] += y;
            if (k != 0)add = x/k;
        }
        else {
            add = x/(k+1);
            scores[0] += add;
        }
        for (ll j=1;j<=n;j++) {
            if (choice[j]==1) {
                scores[j] += add;
            }
        }
    }
    for (ll i=1;i<=n;i++) {
        cout<<scores[i]<<" ";
    }
    cout<<scores[0]<<endl;
    return 0;
}
