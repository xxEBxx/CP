
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
        ll n,x;
        cin >> n>>x;
        vi arr(n);
        ll mn=1e9;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            mn=min(mn,arr[i]);
        }

        ll days = mn/x + 1 ;
        //if (mn%x==0)days++;

        ll stolen = x*(days-1)*n;
        ll res=-1;

        if (days%2 == 0) {

            for (ll i=n-1;i>=0;i--){
                if (arr[i] < days*x ) {
                    res = i;
                    break;
                }
                stolen += x;
            }
        }
        else {
            for (ll i=0;i<n;i++){
                if (arr[i] < (days)*x ) {
                    res = i;
                    break;
                }
                stolen += x;
            }
        }
        cout<<days<<" "<<res+1<<" "<<stolen<<endl;

    return 0;
}
