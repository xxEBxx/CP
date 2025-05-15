#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
vvi mat_mult(vvi a,vvi b){
    vvi res(10,vi(10,0));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                res[i][j] += a[i][k]*b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}
vi mat_vect(vvi mat,vi a){
    vi res(10,0);
    for(int i=0;i<10;i++){
        for(int k=0;k<10;k++){
            res[i] += mat[i][k] * a[k];
            res[i] %= mod;
        }
    }
    return res;
}

vector matrices(22 , vvi (10,vi(10,0)));
void build(){
    vvi mat(10,vi(10,0));
    mat[0][9]=1;
    mat[1][9]=1;
    for(int i=1;i<10;i++)
        mat[i][i-1]=1;

    vvi res(10,vi (10,0));
    for(int i=0;i<10;i++)
        res[i][i]=1;

    for(int i=1;i<22;i++){
        matrices[i] = mat;
        mat=mat_mult(mat,mat);
    }
}


vvi mat_expo(int n){
    vvi res(10,vi (10,0));
    for(int i=0;i<10;i++)
        res[i][i]=1;
    int power=1;
    while(n > 0){
        if(n&1){
            res =  mat_mult(res,matrices[power]);
        }
        n/=2;
        power++;
    }
    return res;
}

int main(){fast();
    build();
    int t;cin>>t;
    while(t--){
        string n;
        int m;
        cin>>n>>m;
        vector<int> arr(10,0);
        for(char letter :n)
            arr[letter-'0']++;
        vvi real_mat = mat_expo(m);
        arr = mat_vect(real_mat,arr);
        int res=0;
        for(int i=0;i<10;i++){
            res+=arr[i];
        }
        cout<<res<<endl;
    }
    return 0;
}