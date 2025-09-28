
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

struct seg {
    ll l,r,i;
};

bool comp(seg a,seg b) {
    return a.l+a.r < b.l+b.r;//we sort by start
}



int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<seg> s(n);
        vi vis(n,0);
        ll tot = 0;
        ll add =0;
        for (ll i = 0; i < n; i++) {
            ll a,b;
            cin>>a>>b;
            s[i] = {a,b,i};
            tot += b-a;
            add += b;
        }

        sort(all(s),comp);
        for (int i = 0; i < n / 2; i++) {
            add -= s[i].r + s[i].l;
        }

        if (n&1){

            ll min_right=1e18;
            for (ll i=n/2;i<n;i++) {
                min_right = min(min_right,s[i].r);
            }
            ll nadd = add-min_right;
            ll max_l_left = -1e18;
            for (ll i=0;i<n/2;i++) {
                max_l_left = max(max_l_left,s[i].l);
            }
            add = max(nadd,add-s[n/2].r-s[n/2].l+max_l_left);

        }
        cout<<tot+add<<endl;


    }
    return 0;
}
