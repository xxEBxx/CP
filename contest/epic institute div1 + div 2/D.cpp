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

const int maxn=5003;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,dp[maxn][maxn],c[maxn];

int solve(int i,int allowed){
    if(i==n+1)return 0;
    if(c[i]==0)return dp[i][allowed]=solve(i+1,allowed);
    if(dp[i][allowed] != -1)return dp[i][allowed];

int res=solve(i+1,allowed+1);
//bob didnt eat them all and let alice eat one of them
    if(allowed >= c[i]){
//is bob allowed to eat all occurences of this number ?Here yes
        res=max(res,1+solve(i+1,allowed-c[i]));
    }
    return dp[i][allowed]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int val;cin>>n;
        for(int i=0;i<=n+1;i++){
            c[i]=0;
            for(int j=0;j<n+2;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            cin>>val;
            c[val]++;
        }
        int used=0;
        for(int i=1;i<=n;i++)if(c[i]>0)used++;
        int res=used-solve(1,0);
        //cout<<used;
        cout<<res<<endl;
    }
    return 0;
}