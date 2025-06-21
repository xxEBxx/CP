#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)1e5+7;
const ll mod = 998244353;

int main(){fast();
    ll t;cin>>t;
    while(t--) {
        ll n,k;cin>>n>>k;
        vi arr(n);

        //pg stores need,elem
        multiset<ll> needed;
        ll res = 0;
        for (ll i=0;i<n;i++) {
            cin>>arr[i];
            for (ll j=0;j<63;j++){
                if  (arr[i]& 1ll<<j)
                    res++;
                else
                    needed.insert(j);
            }
        }


        for (auto elem : needed) {
            if ((1ll<<elem) > k)break;
            k -= 1ll<<elem;
            res++;
        }
        cout<<res<<endl;
    }

        return 0;
    }