
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
    int n,m;
    cin>>n>>m;
    vi r(n),c(m);
    int rx = 0,cx = 0;
    for (int i=0;i<n;i++){
        cin >> r[i];
        if (i<n-1)rx^=r[i];
    }
    for (int i=0;i<m;i++){
        cin >> c[i];
        if (i<m-1)cx^=c[i];
    }
    if (cx^rx == r[n-1]^c[m-1]) {
        vvi res(n,vi (m,0));
        for (int i=0;i<n-1;i++) {
            res[i][m-1] = r[i];
        }
        for (int j=0;j<m-1;j++) {
            res[n-1][j] = c[j];
        }
        res[n-1][m-1] = rx^c[m-1];
        cout<<"YES"<<endl;
        for (int i =0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else {
        cout<<"NO"<<endl;
    }

    return 0;
}
