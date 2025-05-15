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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vi lis(n,1),lds(n,1);
        for(int i=n-1;i>=0;i--){
            int addlis=0,addlds=0;
            for(int j=i+1;j<n;j++){
                if(arr[j] > arr[i])addlis=max(addlis,lis[j]);
                if(arr[j] < arr[i])addlds=max(addlds,lds[j]);
            }
            lis[i]+=addlis;
            lds[i]+=addlds;
        }
        int res=n>0;
        //for(int i=0;i<n;i++)cout<<lis[i]<<" ";cout<<endl;
        //for(int i=0;i<n;i++)cout<<lds[i]<<" ";cout<<endl;

        for(int i=0;i<n;i++)res=max(res,lds[i]+lis[i]-1);
        cout<<res<<endl;
    }
    return 0;
}