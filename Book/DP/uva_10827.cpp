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

const int maxn=(int)76;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[maxn][maxn];

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        vvi arr(n+1,vi (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>arr[i][j];

                dp[i][j]=arr[i][j]
                        +dp[i-1][j]+dp[i][j-1]
                        -dp[i-1][j-1];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        ll res=arr[1][1];
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                for(int ii=1;ii<1+n;ii++){
                    for(int jj=1;jj<1+n;jj++){
                        ll curr;
                        if(i > ii && j > jj){
                            curr=   dp[n][n]
                                    -dp[i-1][n]-dp[n][j-1]
                                    +dp[i-1][j-1]

                                    +dp[ii][jj];
                        }
                        else if(i > ii && j < jj){
                            curr= dp[n][jj]
                                -dp[i-1][jj]-dp[n][j-1]
                                +dp[i-1][j-1]
                                +
                                dp[ii][jj]-dp[ii][j-1];
                        }
                        else if (i<ii && j>jj){
                            curr=dp[ii][n]-dp[i-1][n]-dp[ii][j-1]+dp[i-1][j-1]
                                    +dp[ii][jj]-dp[i-1][jj];
                        }
                        else{
                            curr=dp[i][j]-dp[i-1][j]-dp[i][j-1]+dp[i-1][j-1];
                        }
                        if(curr>res){
                            res=curr;
                            //cout<<"here is i j , curr"<<i<<" "<<j<<" "<<ii<<" "<<jj<<" "<<curr<<endl;
                        }
                    }
                }
            }
        }
        cout<<res<<endl;

    }
    return 0;
}