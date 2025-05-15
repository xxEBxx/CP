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

const int maxn=(int)51;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,m,st_len;
char mat[maxn][maxn];
string arr;
int dp[21][maxn][maxn];

int solve(int index,int i,int j){
    if(index==st_len)return 1;
    if(i<0 || j<0 || i==n || j==m)return 0;
    if(dp[index][i][j]!=-1)return dp[index][i][j];
    int res=0;
    if(arr[index]==mat[i][j] || abs(arr[index]-mat[i][j])==32){
        res =solve(index+1,i-1,j-1)
                |solve(index+1,i-1,j)
                |solve(index+1,i+1,j+1)
                |solve(index+1,i,j-1)
                |solve(index+1,i+1,j)
                |solve(index+1,i,j+1)
                |solve(index+1,i-1,j+1)
                |solve(index+1,i+1,j-1)
                ;
    }
    return dp[index][i][j]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>mat[i];
        }
        int a;cin>>a;
        while(a--){
            memset(dp,-1,sizeof(dp));
            cin>>arr;
            st_len=arr.size();
            bool done=false;
            for (int i = 0; i < n; i++) {
                if(done)break;
                for (int j = 0; j < m; j++) {
                    if (solve(0, i, j)==1) {
                        cout << i + 1 << " " << j + 1 << endl;
                        done=true;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}