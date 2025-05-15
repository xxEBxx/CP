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
    ll n;cin>>n;
    vi arr(n);
    map<ll,vi> index;
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    for(ll i=0;i<n;i++){
        index[arr[i]].push_back(i);
    }
    ll res = -1;
    for(ll i=1;i < n-1;i++){
        ll distance = arr[i] - arr[0];
        ll to_find = arr[n-1] - distance;
        bool found=false;
        for(ll elem : index[to_find]){
            if(elem > 0 && elem <= (i+1) && elem!=i) {
                found = true;
            }
        }
        if(found){
            res=max(res,distance);
        }
    }
    cout<<res<<endl;
    return 0;
}