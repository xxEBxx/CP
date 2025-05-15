#include<bits/stdc++.h>

#define all (v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll ;
typedef pair<ll ,ll > ii;
typedef pair<ll ,ll > pl;
typedef vector<ll > vi;
typedef vector<vector<ll >> vvi;
typedef vector<ll > vl;
typedef vector<vector<ll >> vvl;

const ll maxn=(ll )1e6+7;
const ll mod=(ll )1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll q;cin>>q;

        vector<ll> arr(n);
        map<ll,ll> count;
        ll total=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            count[arr[i]]++;
            if(count[arr[i]]==1 && arr[i]!=0)
                total++;
        }
        //cout<<total<<endl;
        for(ll i=0;i<q;i++){
            ll a;cin>>a;
            if(a==2) {
                cout << total << endl;
            }
            else{
                ll k,v;cin>>k>>v;
                k--;
                ll to_change=0;

                if(arr[k]!=v){
                    if (count[v] == 0 && v != 0) {
                        to_change++;
                    }
                    if (count[arr[k]] == 1 && arr[k] != 0) {
                        to_change--;
                    }
                }

                count[v]++;
                count[arr[k]]--;

                arr[k]=v;
                total += to_change;
            }
        }
    }
    return 0;
}