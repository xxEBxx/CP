
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

vector<ii> arr;
bool comp(ii a,ii b) {
    if (a.f==b.f) {//sort by min diff
        return a.s-a.f < b.s-b.f;
    }
    return a.f > b.f;
}
ii player;    ll n;

ll work(ll x) {
    //can i achieve the xth place
    ll curr = player.f;
    //we start killing from the xth team
    for (ll i = x-1 ; i<n;i++) {
        if (curr >= arr[i].f)return true;
        ll diff = arr[i].s-arr[i].f;
        curr -= diff;
    }
    return curr >= 0ll;
}

int main() {
    fast();
    cin>>n;
    n--;
    arr.resize(n);
    cin>>player.f>>player.s;
    for (ll i=0;i<n;i++) {
        cin>>arr[i].f>>arr[i].s;
    }
    sort(all(arr),comp);

    set<ii> pq;
    ll i =0;
    while (i<n) {
        if (player.f >= arr[i].f)break;
        pq.insert({arr[i].s-arr[i].f+1,i});
        i++;
    }
    //i people are strictly better than me
    //now we keep trying to remove teams ahead
    //size of pq is the
    ll curr = player.f;
    ll res = i+1;
    while (i<n && curr>=0) {
        if (pq.size()==0) {
            res=1;
            break;
        }
        //remove someone
        auto elem = *pq.begin();
        pq.erase(elem);
        curr -= elem.f;
        while (i<n && curr<arr[i].f) {
            pq.insert({arr[i].s-arr[i].f+1,i});
            i++;
        }
        res = min(res,(ll)pq.size()+1);
    }
    cout<<res<<endl;

    return 0;
}
