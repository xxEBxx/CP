#include<bits/stdc++.h>

#define aint(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,int> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<int> vl;
typedef vector<vector<int>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int K=801,N=4001;
int dp[K][N],ps[N][N];

int cost(int i,int j){
    return (ps[j][j]-ps[j][i-1]-ps[i-1][j]+ps[i-1][i-1])/2;
}

void solve(int k,int l,int r,int optl,int optr){
    if(l>r)return ;
    int mid=(l+r)/2;
    int opt=optl;

    for(int i=optl;i <= min(optr,mid);i++){
        if(dp[k][mid] > dp[k-1][i-1] + cost(i,mid)){
            dp[k][mid]=dp[k-1][i-1] + cost(i,mid);
            opt=i;
        }
    }
    solve(k,l,mid-1,optl,opt);
    solve(k,mid+1,r,opt,optr);
}

int main(){fast();
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n; j++) {
            cin >> ps[i][j];
            ps[i][j]+=ps[i][j-1];
        }
        for (int j = 1; j <= n; j++) {
            ps[i][j]+=ps[i-1][j];
        }
    }
    memset(dp, 0x3f, sizeof dp);

    dp[0][0]=0;

    for(int i=1;i<=k;i++){
        solve(i,1,n,1,n);
    }
    cout<<dp[k][n];

    return 0;
}