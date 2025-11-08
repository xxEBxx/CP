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
vi arr;
ll n,k;

bool work(ll d) {
    vi leave(n,0);
    ll curr =0;
    
    for (ll i=0;i<n;i++) {
        curr++;
        ll e = i+(arr[i]+d-1)/d - 1;
        if (e<n)leave[e]++;
        
        if (curr >= k) {
            return false;
        }

        curr-=leave[i];
    }
    
    return true;

}


int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        arr.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll low = 1,high = 1e9;

        while (high - low > 1) {
            ll c = (high + low)/2;
            if (work(c)) {
                high = c;
            }
            else {
                low = c+1;
            }
        }
        if (work(low))
        cout << low << endl;
        else cout << high << endl;


    }
    return 0;
}