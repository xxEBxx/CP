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

bool comp(pair<ll,ll> a,pair<ll,ll> b){
    return a.s > b.s;
}

int main(){fast();
    ifstream cin("pop.in");
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n);
        vector<pair<ll,ll>> pairs;
        cin>>arr[0];
        ll curr_elem=arr[0],curr_size=1;
        for(ll i=1;i<n;i++){
            cin>>arr[i];
            if(arr[i]==arr[i-1]){
                curr_size++;
            }
            else{
                pairs.push_back({curr_elem,curr_size});
                curr_size=1;
                curr_elem=arr[i];
            }
        }
        pairs.push_back({curr_elem,curr_size});
        //for(auto elem : pairs)cout<<elem.f<<" "<<elem.s<<endl;cout<<endl;
        vector<pair<ll,ll>> sor=pairs;
        sort(all(sor),comp);
        ll res ;
        if(sor.size()>=2){
            res=sor[0].s+sor[1].s;
        }
        else{
            res=sor[0].s;
        }
        for(ll i=1;i<sor.size();i++){
            if(pairs[i+1].f == pairs[i-1].f)
                res=max(res,pairs[i-1].s+pairs[i].s+pairs[i+1].s);
        }
        cout<<res<<endl;
    }
    return 0;
}