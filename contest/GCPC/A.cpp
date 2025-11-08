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
        cin >> n;
        vi arr(n);
    ll res=1e18;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]=abs(arr[i]);
            if (arr[i]%2==0)
                res=min(res,arr[i]/2);
        }
    if (res==1e18)
        cout<<-1<<endl;
    else
        cout<<res<<endl;
    
    return 0;
}
