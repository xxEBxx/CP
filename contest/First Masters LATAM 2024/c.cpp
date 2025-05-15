#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll n,m;

vvi product(vvi a,vvi b){
    vvi res(m+1,vi(m+1,0));

    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++){
            ll sum=0;
            for(ll k=1;k<=m;k++){
                sum += a[i][k]*b[k][j];
                sum %= mod;
            }
            res[i][j]=sum;
        }
    }

    return res;
}

vvi expo(vvi mat){

    vvi res(m+1,vi(m+1,0));
    for(ll i=1;i<=m;i++)res[i][i]=1;

    while(n > 0){
        if(n&1){
            res = product(mat,res);
        }
        mat= product(mat,mat);
        n=(n>>1);
    }
    return res;
}

vi matvet(vvi mat,vi arr){
    vi res(m+1,0);
    for(ll i=1;i<=m;i++){
        ll sum=0;
        for(ll j=1;j<=m;j++){
            ll to_add=mat[i][j] * arr[j];
            to_add%=mod;
            sum += to_add;
            sum %= mod;
        }
        res[i]=sum;
    }
    return res;
}

int main(){fast();
    cin>>n>>m;
    n--;
    vvi mat(m+1,vi(m+1,0));

    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++){
            if(i==j)continue;
            if(gcd(i,j)==1){
                mat[i][j]=1;
            }
        }
    }
    mat[1][1]=1;

    mat = expo(mat);
    vi res(m+1,1);
    res[0]=0;

    res = matvet(mat,res);
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans += res[i];
        ans %= mod;
    }
    cout<<ans<<endl;

    return 0;
}