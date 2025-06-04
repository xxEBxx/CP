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
    ll n;cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll res=0,curr=0;
    for(ll i=0;i<n-1;i++){
        if(arr[i]&1){
            if(curr>0){
                if(curr&1){
                    arr[i]+=curr;
                    curr=0;
                }
                else{
                    arr[i]+=curr-1;
                    curr=1;
                }
            }
        }
        else{
            if(curr>0){
                if(curr&1){
                    arr[i]+=curr-1;
                    curr=1;
                }
                else{
                    arr[i]+=curr;
                    curr=0;
                }
            }
        }
        curr += arr[i]/2;
        res += arr[i]/2;
    }
    cout<<res<<endl;
    return 0;
}