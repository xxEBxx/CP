#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = 301;
const int mod = (int) 1e9 + 7;

vvi arr;
int dp[maxn][maxn],vis[maxn][maxn];
int cnt,k,n;

int solve(int i,int w) {
    if (i==n)
        return 0;
    if (vis[i][w] == cnt)
        return dp[i][w];

    int res =-1e9;
    if (w < k) {
        //for row i we take white
        res = solve(i+1,w+1) + arr[i][w];
    }
    if ( i-w < n-k) {
        //for row i we take blak
        res = max(res,solve(i+1,w) + arr[i][k+i-w]);
        // k chosen for whites , i-w chosen black so  farr
    }

    vis[i][w]=cnt;
    return dp[i][w]= res;
}

int main() {
    fast();
    int t;
    cin >> t;
    memset(vis,-1,sizeof(vis));
    while (t--) {
        cin >> n;
        arr.assign(n,vi(n));

        for (int i = 0; i < n; i++) {
            for (int j=0;j<n;j++)
                cin >> arr[i][j];
        }

        int res=-1e9;
        cnt=1;
        for (k=0;k<=n;k++) {
            cnt++;
            res = max(solve(0,0),res);
        }
        cout<<res<<endl;
    }
    return 0;
}
