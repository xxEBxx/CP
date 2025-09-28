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

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int dp[251][251],arr[251],n,ps[251],opt[251][251];

int solve(int a,int b) {
    if (a==b)return arr[a];
    if (b<a)return 0;
    if (dp[a][b]!=-1)
        return dp[a][b];

    int res = ps[b]-ps[a-1],add=1e9;

    for (int i=a;i<=b;i++) {
        add = min(add,solve(a,i-1)+solve(i+1,b));
    }
    return dp[a][b] = res+add;
}

int main() {
    fast();

    while (cin>>n) {
        memset(dp,-1,sizeof(dp));
        memset(arr,0,sizeof(arr));

        for (int i=1;i<=n;i++) {
            cin>>arr[i];
            ps[i] = ps[i-1] + arr[i];
        }

        cout<<solve(1,n)-ps[n]<<endl;

    }
    return 0;
}
