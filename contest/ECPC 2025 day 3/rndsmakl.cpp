
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

const int maxn = (int) 1e5 + 7;
const int mod = (int) 1e9 + 7;

int dp[maxn][2];
unordered_map<int,int> m;

int solve(int n,int start) {
    if (n<0)return 0;
    if (n==0) {
        return 1;
    }
    if (dp[n][start]!=-1)
        return dp[n][start];
    int res=0;
    for (int i=97;i<97+26;i++) {
        if (start==1 && m[(char)i]==1)continue;
        res += solve(n-i,0);
        res %= mod;
    }
    return dp[n][start] = res;

}

int main() {
    fast();
    int n;
    string s;
    cin>>n>>s;
    for (auto elem : s)
        m[elem]++;

    memset(dp,-1,sizeof(dp));

    cout<<solve(n,1)<<endl;
    return 0;
}
