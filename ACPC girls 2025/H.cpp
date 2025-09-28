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


struct comp {
    bool operator()(ii a, ii b) {
        return a.s > b.s;
    }
};

int main() {
    fast();
    ll n,m;
    cin>>n>>m;
    vi d(n+1,-1);
    priority_queue<ii,vector<ii>,comp> q;
    //keep only the edge that took them there
    for (ll i=0;i<m;i++) {
        ll val;cin>>val;
        //d[val]=0;
        q.push({val-1,0});
    }
    vvi p(n,vi(n,0));
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<n;j++) {
            cin>>p[i][j];
        }
    }
    ll res=0;
    while (!q.empty()) {
        auto head = q.top();
        q.pop();
        if (d[head.f] != -1)
            continue;
        res += head.s;
        d[head.f] = head.s;
        for (ll i=0;i<n;i++) {
            if (d[i] != -1)continue;
            q.push({i,p[i][head.f]});
        }
    }
    cout<<res<<endl;
    return 0;
}
