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

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

int main(){fast();
    ll t;cin>>t;
    while(t--){
        string ss;cin>>ss;
        ll n=ss.size();
        vi s(n+1,0);
        for(ll i=1;i<=n;i++){
            s[i] = s[i-1] + (ss[i-1]-'0')*2 -1;
        }

        map<ll,ll> pref;
        ll res = 0 ;
        for(ll i=0;i<=n;i++){
            res += pref[s[i]] * (n-i+1);
            res%=mod;
            pref[s[i]] += i+1;
            pref[s[i]] %= mod;
        }
        cout<<res<<endl;
    }
    return 0;
}