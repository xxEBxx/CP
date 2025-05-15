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
        ll n;cin>>n;
        vvi arr(1,vi(n));
        for(ll i=0;i<n;i++){
            cin>>arr[0][i];
        }
        ll res=0;
        for(ll j=30;j>=0;j--){

            vvi next_arr;
            for(auto v : arr){
                vi v1,v2;
                for(ll elem : v){
                    if((elem>>j) %2 ==1) {
                        v1.push_back(elem);
                    }
                    else
                        v2.push_back(elem);
                }
                if(!v1.empty())next_arr.push_back(v1);
                if(!v2.empty())next_arr.push_back(v2);
                res += j * v1.size() * v2.size();
            }
            arr = next_arr;
        }
        cout<<res<<endl;

    }
    return 0;
}