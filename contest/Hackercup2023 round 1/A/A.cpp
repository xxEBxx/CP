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
    int t,tt=0;cin>>t;
    while(t--){tt++;
        cout<<"Case #"<<tt<<": ";
        int n;cin>>n;
        vector<float> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(all(arr));
        if(n==5){
            float res;
            if(arr[2]-arr[0] > arr[4]-arr[2]){
                //join the second part
                res= (arr[4]+arr[2])/2 - (arr[1]+arr[0])/2;
            }
            else{
                res= (arr[4]+arr[3])/2 - (arr[2]+arr[0])/2;
            }
            cout<<res<<endl;
            continue;
        }
        float ans = -((arr[1]+arr[0])/2) + ((arr[n-2]+arr[n-1])/2);
        cout<<ans<<endl;
    }
    return 0;
}