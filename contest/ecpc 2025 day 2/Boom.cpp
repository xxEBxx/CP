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
    cin>>t;
    while(t--){
       ll n;
        cin>>n;
        vi arr(n);
        unordered_map<ll,ll> s;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            s[arr[i]]=1;
        }
        sort(all(arr));
        ll res=0;

        for(ll i=0;i<n;i++){
            ll curr=arr[i];
            if (s[curr]==0)continue;
            ll loc=0;
            while(curr <= (ll)1e9){
                if (s[curr]>0)loc=1;

                s[curr]=0;
                curr*=2;
            }
            res+=loc;
        }
cout<<res<<endl;



}
    return 0;
}
