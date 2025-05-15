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
        ll n,k1,k2;cin>>n>>k1>>k2;
        vector<ll> a(n),b(n);
        multiset<ll> diff;
        for(ll i=0;i<n;i++)
            cin>>a[i];
        for(ll i=0;i<n;i++)
            cin>>b[i];
        for(ll i=0;i<n;i++)
            diff.insert(abs(a[i]-b[i]));
        ll k=k1+k2;
        while(k>0){
            ll max_elem=*prev(diff.end());
            diff.erase(prev(diff.end()));
            if(max_elem==0)
                diff.insert(1);
            else
                diff.insert(max_elem-1);
            k--;
        }

        ll res=0;
        for(auto elem : diff)
            res+=elem*elem;
        cout<<res<<endl;


    return 0;
}