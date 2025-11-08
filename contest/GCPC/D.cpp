
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
vi a,b,arr;
ll n,x;

ii work(ll k) {
    vector<ii> arr(n);
    for (ll i=0;i<n;i++) {
        arr[i]={a[i],b[i]};
    }
    sort(all(arr),[&](ii a,ii b) {
        return a.f + k * a.s < b.f + k * b.s;
    });
    ll res =0;
    for (ll i=0;i<k;i++) {
        res += arr[i].f + k*arr[i].s;
    }
    if (res > x)return {-1,-1};
    return {k,res};
}

int main() {
    fast();
    cin>>n>>x;
    a.resize(n);
    b.resize(n);
    for (ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for (ll i=0;i<n;i++) {
        cin>>b[i];
    }

    ll h=n,l=0;
    while (l+1<h) {
        ll mid = (l+h)/2;
        if (work(mid).f != -1) {
            //it is working
            l = mid;
        }
        else {
            h = mid-1;
        }
    }
    if (work(h).f != -1)
        cout<<work(h).f<<" "<<work(h).s<<endl;
    else
        cout<<work(l).f<<" "<<work(l).s<<endl;


    return 0;
}
