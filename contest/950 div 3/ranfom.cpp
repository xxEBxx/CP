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
        ll n,l,r;cin>>n>>l>>r;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll curr=arr[0],res=0;
        ll i=0,j=0;
        while(i < n){
            //cout<<"here is i j curr"<<i<<j<<curr<<endl;
            if(curr>=l && curr<=r){
                //cout<<"entered at i j"<<i<<" "<<j<<endl;
                res++;
                i++;
                j=i;
                curr=arr[i];
            }
            else if(curr > r){
                curr-=arr[j];
                j++;
                if(j>i) { i = j;curr=arr[i] ;}
            }
            else{
                i++;
                curr+=arr[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}