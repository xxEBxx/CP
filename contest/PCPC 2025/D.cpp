
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

int main() {
    fast();
    int n,m,x;
    cin>>n>>m>>x;
    vvi arr(n+1,vi(m+1,0));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>arr[i][j];
            if (arr[i][j] > x)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    int res=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=1;k<=min(n,m);k++) {
                int i1 = i+k-1,j1=j+k-1;
                if (i1>n || j1>m)break;
                int cnt = arr[i1][j1]- arr[i-1][j1]-arr[i1][j-1]+arr[i-1][j-1];
                int sz = k*k;
                if (cnt > sz-cnt)continue;
                res = max(res,sz);
            }
        }
    }
    cout<<res<<endl;

    return 0;
}
