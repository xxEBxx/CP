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

const int maxn=(int)1e5 * 2 + 7 ;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int logg=30;
vvi rq(maxn+1,vi (logg+1,-1));
vi lg(maxn,-1);

vi a(maxn);
vi b(maxn);
int better(int i,int j){
    if(a[i]!=a[j]){
        if(a[i] > a[j]){
            return i;
        }
        return j;
    }
    if(b[i]!=b[j]){
        if(b[i]<b[j]){
            return i;
        }
        return j;
    }
    return min(i,j);
}


void preprocess(int n){
    for(int i=1;i <= n;i++){
        rq[i][0]=i;
    }
    //from l=1 to r=1 best element is 1
    for(int j=1;j<=logg;j++){
        for(int i=1 ; i +(1<<(j-1)) <= n ;i++){
            rq[i][j]=better(rq[i][j-1],rq[i+(1<<(j-1))][j-1]);
        }
    }
}

int main(){fast();
    int n,m;cin>>n;
    lg[1]=0;//maxn puissance de 2 plus petite que i
    for(int i=2;i<=n;i++){
        lg[i]=lg[i>>1] + 1;
    }
    for(int i=1;i<=n;i++) cin >>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    cin>>m;
    preprocess(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        int distance=y-x+1,puiss = lg[distance];
           cout<< better (rq[x][puiss],rq[y-(1<<puiss)+1][puiss])<<endl;
    }
    return 0;
}