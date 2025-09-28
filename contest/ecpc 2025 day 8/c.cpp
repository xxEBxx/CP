
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
    int n,m,k;
    cin>>n>>m>>k;
    vvi arr(n+1,vi(m+1,0));
    for (int i=0;i<k;i++) {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    int res=0;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            for (int d=1;d<=min(n,m);d++) {
                if (i+d>n || j+d>m)break;
                if (arr[i][j]==1 && arr[i+d][j]==1 && arr[i+d][j+d]==1 && arr[i][j+d]==1) {

                    res++;
                }
            }
        }
    }
    cout<<res;

    return 0;
}
