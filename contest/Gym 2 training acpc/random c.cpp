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
        int n,m,v;cin>>n>>m>>v;
        vector<int> arr(n+1,0),ps(n+1,0),pre(n+1,0),suff(n+1,0);
        for(int i=1;i<1+n;i++){
            cin>>arr[i];
            ps[i]=ps[i-1]+arr[i];
        }
        //pre[i] is number of monsters food from 1 to i inclusive
        int reste=arr[1];
        for(int i=2;i<1+n;i++){
            pre[i]=pre[i-1];
            if(reste>=v){
                reste=0;
                pre[i]++;
            }
            reste+=arr[i];
        }
        reste=0;
        for(int i=n-1;i>0;i--){
            reste+=arr[i];
            suff[i]=suff[i+1];
            if(reste>=v){
                reste=0;
                suff[i]++;
            }
        }
        for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)cout<<suff[i]<<" ";

        int i=1,j=1;
        int res=-1;
        while(j < n+1){
            if(suff[j]+pre[i]>=m){
                res=max(res,ps[j-1]-ps[i-1]);
                j++;
            }
            i++;
        }
        cout<<res<<endl;
    }
    return 0;
}