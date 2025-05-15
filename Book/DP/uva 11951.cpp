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

const int maxn=(int)101;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[maxn][maxn];

int main(){fast();
    int t;cin>>t;int out=0;
    while(t--){
        out++;
        int n,m,k;cin>>n>>m>>k;
        vvi arr(1+n,vi(m+1,0));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                cin>>arr[i][j];
                dp[i][j]=arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
             //   cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }
        ll answer_s=0,answer_price=k;
        for(int i=1;i<=n;i++){
            //cout<<"her i s s"<<i<<endl;
            for(int j=1;j<=m;j++){
                for(int ii=i;ii<=n;ii++){
                    for(int jj=j;jj<=m;jj++){
                        ll price=dp[ii][jj]-dp[i-1][jj]-dp[ii][j-1]+dp[i-1][j-1];
                        ll curr_size=(ii-i+1)*(jj-j+1);
                        if(price <= k){
                            if(curr_size > answer_s) { answer_s = curr_size; answer_price=price;}
                            if(curr_size == answer_s && price < answer_price)answer_price=price;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<out<<": "<<answer_s<<" "<<answer_price<<endl;
    }
    return 0;
}