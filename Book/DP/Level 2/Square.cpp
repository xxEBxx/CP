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

int dp[1<<20],n,total,arr[20];

int solve(int bitmask,int len){
    if(len > total/4)return 0;
    if(dp[bitmask]!=-1)return dp[bitmask];

    if(len == total/4){
        if(bitmask==((1<<n)-1))return 1;
        len=0;
    }
    int res=0;

    for(int i=0;i<n;i++){
        if(((bitmask>>i)&1) == 0){
            res|=solve(bitmask|(1<<i),len+arr[i]);
        }
    }

    return dp[bitmask]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        total=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            total+=arr[i];
        }
        if(total%4 != 0){
            cout<<"no"<<endl;
            continue;
        }
        //cout<<total<<endl;
        int res=solve(0,0);
        if(res==0)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}