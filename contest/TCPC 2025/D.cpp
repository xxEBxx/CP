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

const int maxn = 501;
const int mod = (int) 1e9 + 7;

int maxv2,m,dp[maxn][maxn][2][50],n;

string t;

bool vow(char c) {
    return  (c=='a' || c=='e'  || c=='i' || c=='u' || c=='o');
}

int solve(int i,int j,int last,int count) {
    if (count+count*count > n)
        return 0;

    if (i==n)
        return j==m;

    if (dp[i][j][last][count] != -1)
        return dp[i][j][last][count];

    int res=0;
    for (char c = 'a';c<='z';c++) {
        int nj=j,nlast=0,ncount=count;
        if (vow(c)) {
            if (last==1)continue;
            ncount++;
            nlast = 1;
        }
        if (j<m && c == t[j])nj++;
        res += solve(i+1,nj,nlast,ncount);
        res %= mod;
    }
    return dp[i][j][last][count] = res;

}

int main() {
    fast();
    cin>>n>>m>>t;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0,0)<<endl;
    return 0;
}
