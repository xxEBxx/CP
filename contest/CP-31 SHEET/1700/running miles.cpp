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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n+1),pre(n+1,0),suff(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            pre[i]  = arr[i]+i;
            suff[i] = arr[i]-i;
        }
        for(int i=1;i<=n;i++)
            pre[i]=max(pre[i],pre[i-1]);

        for(int i=n-1;i>0;i--)
            suff[i]=max(suff[i],suff[i+1]);

        int res=0;
        for(int i=2;i<n;i++){
            res=max(res,suff[i+1]+pre[i-1]+arr[i]);
        }
        cout<<res<<endl;

    }
    return 0;
}