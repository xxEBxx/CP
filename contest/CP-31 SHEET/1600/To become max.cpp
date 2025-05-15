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
        int n,k;cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int res=0;
        for(int j=0;j<n;j++){
            int k_copy=k;
            res=max(res,arr[j]);
            int added = 0;
            for(int i=j-1;i>=0;i--){
                added++;
                if(arr[i] > added+arr[j] || k_copy < arr[j]+added-arr[i])break;
                k_copy -= arr[j]+added-arr[i];
                res=max(res,arr[j]+added);
            }
        }
        for(int j=1;j<n-1;j++){
            int k_copy=k;
            if(arr[j-1]-arr[j+1]>1)continue;
            k_copy -= arr[j-1]-arr[j];//replace arr[j] with arr[j-1] as it is hte new value
            if(k_copy<=0)continue;
            int added = 0;
            for(int i=j-1;i>=0;i--){
                added++;
                if(arr[i] > added+arr[j-1] || k_copy < arr[j-1]+added-arr[i])break;
                k_copy -= arr[j-1]+added-arr[i];
                res=max(res,arr[j-1]+added);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}