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
    int t;cin>>t;
    while(t--){
        int n,k,z;cin>>n>>k>>z;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
// know the idea is that we see the max pair and try to repeat it
// min(z,(k-index of max pair)/2)
        int answer=0;
        for(int back=0;back<=z;back++){
            int res=arr[0],max_pair=0;
            for(int i=1;i <= k-2*back;i++){
                if(back<z && i>=2 && i==k-2*back) res += max(arr[i],arr[i-2]);
                else res+=arr[i];
                max_pair=max(max_pair,arr[i]+arr[i-1]);
            }
            res += max_pair*back;
            //cout<<back<<" "<<res<<" "<<max_pair<<endl;
            answer=max(answer,res);
        }
        cout<<answer<<endl;


    }
    return 0;
}