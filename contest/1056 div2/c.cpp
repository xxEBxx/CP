
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

int main() {
    fast();
    ll n,q,c;
    cin>>n>>q>>c;
    vector<vvi> mat(c+2,vvi(101,vi(101,-1)));
    //brightness goes to c valid , c+1 is invalid , meaning it is modulo c+1
    for (ll i=0;i<n;i++) {
        ll x,y,val;
        cin>>x>>y>>val;
        for (int t=0;t<=c;t++) {
            if (mat[t][x][y]!=-1)mat[t][x][y] += val;
            else mat[t][x][y] = val;
            val++;
            val %= (c+1);
        }
        //mat[0][x][y] = val;//at t=0
    }
    /*for (ll t=1;t<=c;t++) {
        for (ll i =0;i<101;i++) {
            for (ll j=0;j<101;j++) {
                if (mat[t-1][i][j]==-1)continue;
                mat[t][i][j] = 1+mat[t-1][i][j];
                mat[t][i][j] %= (c+1);
            }
        }
    }*/

    for (ll t=0;t<=c;t++) {
        for (ll i=0;i<101;i++){
            mat[t][i][0] = 0;
            mat[t][0][i] = 0;
        }

        for (ll i =1;i<101;i++) {
            for (ll j=1;j<101;j++) {
                if (mat[t][i][j] == -1) {
                    mat[t][i][j] = mat[t][i-1][j]+mat[t][i][j-1]-mat[t][i-1][j-1];
                }
                else {
                    mat[t][i][j] += mat[t][i-1][j]+mat[t][i][j-1]-mat[t][i-1][j-1];
                }

            }
        }
    }
    for (ll i=0;i<q;i++) {
        ll x1,y1,x2,y2,t;
        cin>>t>>x1>>y1>>x2>>y2;
        t %= (c+1);
        ll res = mat[t][x2][y2] - mat[t][x1-1][y2] -mat[t][x2][y1-1] + mat[t][x1-1][y1-1];
        cout<<res<<endl;
    }

    return 0;
}
