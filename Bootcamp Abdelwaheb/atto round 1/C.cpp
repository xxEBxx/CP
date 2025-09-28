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
    ll n;
    cin>>n;
    vi arr(n);
    vector<ii> l(n,{-1,-1}), r(n,{n,n});
    // .f means smaller and .s means bigger index
    for (ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    stack<ii> s;
    // minimum left
    for (ll i=0;i<n;i++) {
        while (!s.empty() && s.top().f >= arr[i]) s.pop();
        if (!s.empty())
            l[i].f = s.top().s ;
        s.push({arr[i],i});
    }
    while (!s.empty()) s.pop();
    //minimum right
    for (ll i=n-1;i>=0;i--) {
        while (!s.empty() && s.top().f > arr[i]) {
            s.pop();
        }
        if (!s.empty())
            r[i].f = s.top().s ;
        s.push({arr[i],i});
    }
    while (!s.empty()) s.pop();
    // max left
    for (ll i =0;i<n;i++) {
        while (!s.empty() && s.top().f < arr[i]) {
            s.pop();
        }
        if (!s.empty())
            l[i].s = s.top().s ;
        s.push({arr[i],i});
    }
    while (!s.empty()) s.pop();
    //max right
    for (ll i=n-1;i>=0;i--) {
        while (!s.empty() && s.top().f <= arr[i])
            s.pop();
        if (!s.empty())
            r[i].s = s.top().s ;
        s.push({arr[i],i});
    }

    ll mn=0,mx=0;
    for (ll i=0;i<n;i++) {
        ll d_min = (r[i].s - i) * (i - l[i].s);
        ll d_max = (r[i].f - i) * (i - l[i].f);

        mn += d_min * arr[i];
        mx += d_max * arr[i];
    }

    cout<<mn-mx<<endl;
    return 0;
}
