
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
        ll n,k,l,r;
        cin >> n>>k>>l>>r;
        vi arr(n);
        vi next(n,-1);
        unordered_map<ll,ll> last;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            if (last[arr[i]] != 0)
                next[last[arr[i]]-1] = i;
            last[arr[i]]=i+1;
        }
        vi comp = arr;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (ll &x : arr) x = int(lower_bound(comp.begin(), comp.end(), x) - comp.begin());

        vector<int> freq(comp.size(), 0);

        ll dist=0;
        ll fk=0,lk=0,res=0;
        for (ll i=0;i<n;i++) {

            while (fk < n && dist < k) {
                freq[arr[fk]]++;
                if (freq[arr[fk]] == 1) ++dist;
                fk++;
            }
            if (dist < k) break;

            lk = max(lk,fk);
            while (lk < n && freq[arr[lk]] > 0) {
                lk++;
            }
            ll fg = fk-1,lg = lk-1;
            //now we need the llersection between
            //i+l and i+r with fk and lk
            ll loc = min(lg,i+r-1) - max(fg,i+l-1)+1;
            res += max(0ll,loc);

            freq[arr[i]]--;
            if (freq[arr[i]]==0) {
                dist--;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
