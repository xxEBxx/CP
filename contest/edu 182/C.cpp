
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
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<n;j++) {
            for (ll k =0;k<n;k++) {
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

    for (ll i=0;i<n;i++) {
        for (ll j=0;j<n;j++) {
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
    fast();
    ll n,k;
    cin>>n>>k;
    vvi A(n,vi(n,0)),B(n,vi(n,0));
    vi arr(n);
    for (ll i=0;i<n;i++)
        cin>>arr[i];
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<=i;j++) {
            A[i][j] = j+1;
        }
    }

    for (ll i=0;i<n;i++) {
        for (ll j=0;j<=i;j++) {
            B[i][j] = i+1-j;
        }
    }

    vvi mat = mat_mult(B,A);
    mat = mat_expo(mat,k/2);
    if (k&1)
        mat = mat_mult(A,mat);

    vi res = mult_vect(mat,arr);
    for (auto elem : res)
        cout<<elem<< " ";

    return 0;
}
