
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second
#define sz(a) a.size()
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

struct FT {
    vector<ll> s;
    FT(ll n) : s(n,0) {}
    void update(ll pos, ll dif) { // a [ pos ] += d i f
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(ll pos) { // sum of values in [0 , pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }

};

bool comp(array<ll,4> a,array<ll,4> b) {
    return a[2] < b[2];
}

int main() {
    fast();

        ll n;
        cin >> n;
        vi arr(n+1);
        unordered_map<ll,vi> m;//m[k] = all indexes that have this k
        set<ll> all_k;
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            m[arr[i]].push_back(i);
            all_k.insert(arr[i]);
        }
        
        ll q;
        cin>>q;
        vector<array<ll,4>> qs(q);
        for (ll i=0;i<q;i++) {
            cin>>qs[i][0]>>qs[i][1]>>qs[i][2];
            qs[i][3] = i;
        }
        sort(all(qs),comp);
        ll curr_k=0;
        FT ft(n+1);
        vi ans(q+1);
        
        for (ll i =0;i<q;i++) {
            while (true) {
                auto it = all_k.upper_bound(curr_k);
                if (it == all_k.end() || *it > qs[i][2]) break;
                curr_k = *it;
                for (auto index : m[curr_k]) {
                    ft.update(index - 1, arr[index]); // 0-based update
                }
            }
            ans[qs[i][3]] = ft.query(qs[i][1]) - ft.query(qs[i][0]-1); 
        }
        
        for (ll i=1;i<=q;i++) {
            cout<<ans[i-1]<<endl;
        }
        

    return 0;
}
