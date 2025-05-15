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
        vector<int> arr(n+1,0),ps(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            ps[i] = arr[i]^ps[i-1];
        }
        bool res = ps[n]==0;
        //we will have 2 part (xor null) or 3 parts , more can be reducd
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //start to i == i to j == j to n
                res |= (ps[i] == (ps[j]^ps[i])) && ((ps[j]^ps[i]) == (ps[n]^ps[j]));
            }
        }
        if(res)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}