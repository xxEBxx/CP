//link ; https://vjudge.net/problem/UVA-11456
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
        vector<int> lis(n,1),lds(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] > arr[i]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,lis[i]+lds[i]-1);
        }
        cout<<res<<endl;
    }
    return 0;
}