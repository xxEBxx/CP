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
    int t;cin>>t;int tt=0;
    while(t--){tt++;
        int n;cin>>n;
        vector<int> arr(n),weight(n),lis(n),lds(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>weight[i];
            lds[i]=lis[i]=weight[i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j])lds[i]=max(lds[i],weight[i]+lds[j]);
                if(arr[i] < arr[j]) lis[i]=max(lis[i],weight[i]+lis[j]);
            }
        }

        int inc=0,dec=0;
        for(int i=0;i<n;i++){
            if(lds[i]>dec)dec=lds[i];
            if(lis[i]>inc)inc=lis[i];
        }

        if(inc>=dec)printf("Case %d. Increasing (%d). Decreasing (%d).\n",tt,inc,dec);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n",tt,dec,inc);
    }
    return 0;
}