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

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n+1),ps(n+1,0);
        string s;cin>>s;
        s='a'+s;
        unordered_map<ll,ll> m;
        m[0]=1;
        for(ll i=1;i<=n;i++){
            arr[i] = s[i]-'0';
            ps[i] = arr[i]+ps[i-1];
            m[ps[i] - i]++;
        }

        ll res=0;
        for(auto elem : m){
            res += elem.s * (elem.s-1)/2;
        }
        cout<<res<<endl;

    }
    return 0;
}