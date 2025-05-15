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

        vvi arr(2*n+1,vi (2*n+1,0)),dp(n*2+1,vi (2*n+1,0));

        for(int i=1;i<= n;i++){
            for(int j=1;j<= n;j++){
                cin>>arr[i][j];
                arr[i+n][j]=arr[i+n][j+n]=arr[i][j+n]=arr[i][j];
            }
        }
        for(int i=1;i <= 2*n ;i++){
            for(int j=1;j <= 2*n ; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
            }
        }

        int res=-100;

        for(int i=1; i<= 2*n;i++){
            for(int j=1;j<=2*n;j++){
                for(int ii=i; ii < min(2*n+1,i+n);ii++){
                    for(int jj=j ; jj<min(2*n+1,j+n) ; jj++){
                        res=max(res,
                            dp[ii][jj]
                            -dp[ii][j-1]-dp[i-1][jj]
                            +dp[i-1][j-1]
                                );
                    }
                }
            }
        }

        cout<<res<<endl;

    }
    return 0;
}