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
       ll a,b,x,y;
        cin>>a>>b>>x>>y;
        if (a&1 && a-1 == b) {
            cout<<y<<endl;
        }
        else if (b>=a){
           ll res = 0;
           for (ll i = a; i < b; i++) {
           if (i & 1)
               res += x;
           else
               res += min(x, y);
       }
       cout << res << endl;
        }
       else{
           cout<<-1<<endl;
        }
    }
    return 0;
}

