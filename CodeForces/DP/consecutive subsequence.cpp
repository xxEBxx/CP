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
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        map<int,int> g;
        g[arr[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            g[arr[i]]=g[arr[i]+1]+1;
        }
        int res=0,last_one;
        for(int i=0;i<n;i++) {
            if(g[arr[i]] > res){
                last_one=arr[i];
                res=g[arr[i]];
            }
        }
        cout<<res<<endl;
        last_one--;
        vi ans;
        for(int i=0;i<n;i++){
            if(arr[i] == 1 + last_one){
                last_one=arr[i];
                ans.push_back(i+1);
            }
        }
        for(int i:ans)cout<<i<<" ";

    return 0;
}