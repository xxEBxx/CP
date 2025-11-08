

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
        ll n;
        cin >> n;
        vi arr(n);
        unordered_map<ll,ll> freq;
        ll tot=0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            tot+=arr[i];
            freq[arr[i]]++;
        }
        ll perim=0;
        vi odd;
        ll even=0;
        for (auto elem :freq) {
            perim += elem.f * ((elem.s/2) * 2);
            if (elem.s%2==1) {
                odd.push_back(elem.f);
            }
            even += elem.s/2;
        }
        sort(all(odd));

        ll add=0;
        if (odd.size()>=2 ) {
            for (ll i =(ll)odd.size()-1;i>=1;i--) {
                if (odd[i]-odd[i-1] < perim ){
                    add = odd[i] + odd[i - 1];
                    break;
                }
            }
        }

        for (auto elem : odd) {
            if (elem >= perim)break;
            add = max(add,elem);
        }

        if (even>1 || even==1 && add>0)cout<<perim+add<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
