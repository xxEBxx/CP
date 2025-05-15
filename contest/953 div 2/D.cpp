#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n,c;cin>>n>>c;
        vector<ll > arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        arr[0]+=c;
        vector<ll> res(n),ps(n);
        ps[0]=arr[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+arr[i];
        }
        ll max_val=0,max_index=0;
        for(int i=0;i<n;i++){
            if(arr[i] > max_val){
                max_val=arr[i];
                max_index=i;
            }
        }
        for(int i=0;i<n;i++){
            if(max_index==i){
                res[i]=0;
                continue;
            }
            res[i]=i;
            //cout<<"here is ps and i"<<ps[i]<<" "<<i<<endl;
            if(ps[i] < max_val){
                res[i]++;
            }
        }
        for(ll k:res){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}