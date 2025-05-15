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
        int n;cin>>n;
        vector<int> arr(n),arr1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            int w;cin>>w;
            for(int j=0;j<w;j++){
                arr1.push_back(arr[i]);
            }
        }
        arr=arr1;
        n=arr.size();
        //first is heights second is widths
        int k = 0, lis_end = 0;
        vi L(n,0),L_id(n,0),p(n,-1);
        for (int i = 0; i < n; i++) {
            //cout<<"here is arr[i]"<<arr[i]<<endl;
            int pos = lower_bound(L.begin(), L.begin()+k, arr[i]) - L.begin();
            //cout<<"here is pos"<<pos<<" "<<L.size()-1<<" "<<k<<endl;
            L[pos] = arr[i];
            L_id[pos] = i;
            p[i] = pos ? L_id[pos-1] : -1;
            if (pos == k ) {
                k = pos+1;
                lis_end = i;
            }
        }
        int width1=0;
        for(int i=0)

    }
    return 0;
}