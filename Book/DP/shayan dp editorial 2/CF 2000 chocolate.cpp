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

ll dp[31][31][51];
ll solve(int i,int j,int k){
    if(i*j==k || k==0)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    ll res=1e14;

    for(int divide_i=1;divide_i<i;divide_i++){
        for(int divide_k=0;divide_k<=k;divide_k++){
            res=min(res,
                    j*j+
                    solve(divide_i,j,divide_k)+
                    solve(i-divide_i,j,k-divide_k));
        }
    }

    for(int divide_j=1;divide_j<j;divide_j++){
        for(int divide_k=0;divide_k<=k;divide_k++){
            res=min(res,
                    i*i+
                    solve(i,divide_j,divide_k)+
                    solve(i,j-divide_j,k-divide_k));
        }
    }

    return dp[i][j][k]=res;

}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    int t;cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        ll res=solve(n,m,k);
        cout<<res<<endl;
    }
    return 0;
}