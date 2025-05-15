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
        cin>>arr[0];
        int a=arr[0];
        for(int i=1;i<n;i++){
            cin>>arr[i];
            a&=arr[i];
        }
        map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(((arr[i]>>j) &1) ==0){
                    m[j]++;
                }
            }
        }
        int res=1e9;
        for(auto elem : m){
            res=min(res,elem.s);
        }
        cout<<res<<endl;

    }
    return 0;
}