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
        vector<ll> arr(n),next_arr;
        ll min_elem=1e9+1;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            min_elem=min(min_elem,arr[i]);
        }

        for(int i=0;i<n;i++){
            if(arr[i]==arr[i+1])
        }

        ll i=0,j=n-1;
        while(i<n && arr[i]==min_elem){
            i++;
        }
        while(j>=0 && arr[j]==min_elem){
            j--;
        }
        ll middle=1ll;
        for(ll loc=i;loc<=j;loc++){
            if(arr[loc]==min_elem) {
                middle = 0ll;
                break;
            }
        }
        cout<<min_elem*n + max(0ll,j-i + middle)<<endl;


    }
    return 0;
}