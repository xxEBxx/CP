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

vvi mat_mult(vvi a,vvi b){
    ll n=a.size();
    vvi res(n,vi(n,0));
    for (ll i=1;i<n;i++) {
        for (ll j=1;j<n;j++) {
            for (ll k =1;k<n;k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vi mult_vect(vvi a,vi b) {
    ll n=a.size();
    vi res(n,0);

    for (ll i=1;i<n;i++) {
        for (ll j=1;j<n;j++) {
            res[i] += a[i][j]*b[j];
            res[i] %= mod;
        }
    }
    return res;
}

vvi mat_expo(vvi a,ll k) {
    ll n=a.size();
    vvi ans(n,vi(n,0)),expo = a;
    for (ll i=0;i<n;i++)ans[i][i]=1;
    while (k>0) {
        if (k&1) {
            ans = mat_mult(ans,expo);
        }
        expo = mat_mult(expo,expo);
        k>>=1;
    }
    return ans;
}

int main() {
    //fast();
    ll t;
    scanf("%lld",&t);
    vvi I(102,vi(102,0));
    for (ll i=1;i<=101;i++)
        I[i][i]=1;
    vvi mat =I;
    while (t--) {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        vi visited(n+2,0);
        mat = I;

        for (ll ii =1;ii<=n;ii++) {
            ll val;
            scanf("%lld",&val);
            vvi loc =I;
            for (ll j=1;j<val;j++) {
                //if (visited[j]==1)
                    loc[val][j]=1;
            }
            loc[val][n+1] = 1 ;
            mat = mat_mult(loc,mat);
            visited[val]=1;
        }
        mat = mat_expo(mat,k);
        vi res (n+2,0);
        res[n+1] = 1;
        res = mult_vect(mat,res);
        for (ll i=1;i<=n;i++)
            printf("%lld ",res[i]);
        printf("\n");

    }

    return 0;
}
