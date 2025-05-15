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

const int maxn=101;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,dp[maxn][maxn][4],bitmask;
vector<string> arr(maxn);

int index_letter(int i,int j){
    if(arr[i][j] >= 'A')
        return (int)(arr[i][j]-'A');
    return (int)(arr[i][j]-'a');
}
//we give i j bitmask and it checks if it is valid
bool valid(int i, int j) {
    // Ensure i and j are within bounds before accessing arr[i][j]
    if (i < 0 || j < 0 || i >= n || j >= n) {
        return false; // Out of bounds is automatically invalid
    }

    int index = index_letter(i, j);
    if (isupper(arr[i][j])) {
        return (bitmask >> index & 1) == 1; // uppercase valid if the bit is set
    }
    return (bitmask >> index & 1) == 0; // lowercase valid if the bit is not set
}



int solve(int i,int j,int from){
    if(i==n-1 && j==n-1 ){
        if(valid(i,j))
            return 1;
        return 1e9;
    }
    else if(i>=n || j>=n || i<0 || j<0){
        return 1e9;
    }
    if(dp[i][j][from] != -1)
        return dp[i][j][from];
    int res=1e9;
    if(valid(i,j)){
        if(from!=0)
            res=min(res, 1 + solve(i-1,j,2));
        if(from!=2)
            res=min(res, 1 + solve(i+1,j,0));

        if(from!=1)
            res=min(res,1 + solve(i,j+1,3));
        if(from!=3)
            res=min(res,1 + solve(i,j-1,1));
    }

    return dp[i][j][from]=res;
}

int main(){fast();
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int res=1e9;
        for(int i=0;i<(1<<10);i++){
            bitmask=i;
            memset(dp,-1,sizeof(dp));
            res=min(res,solve(0,0,0));
            res=min(res,solve(0,0,1));
        }
        cout<<res<<endl;
    }
    return 0;
}