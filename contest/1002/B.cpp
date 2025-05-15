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
        if(n==2){
            if(arr[1]==1)
                cout<<2<<endl;
            else
                cout<<1<<endl;
        }
        else if(n==k){
            int res=n/2+1;
            for(int i=1;i<n;i+=2){
                if(arr[i] != (i+1)/2){
                    res=(i+1)/2;
                    break;
                }
            }
            cout<<res<<endl;
        }
        else{
            int res=2;
            for(int i=1;i <= n-k+1;i++){
                if(arr[i]!=1){
                    res=1;
                    break;
                }
            }
            cout<<res<<endl;

        }
    }
    return 0;
}