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
vi arr(maxn);

const int logg=19;
vvi rq(maxn+1,vi (logg+1,-1));

void preprocess(int n){
    for(int i=0;i < n;i++){
        rq[i][0]=arr[i];
    }
    for(int j=1;j<=logg && (1<<j) <= n;j++){
        for(int i=0;i +(1<<j) <= n ;i++){
            rq[i][j]=min(rq[i][j-1],rq[i+(1<<(j-1))][j-1]);
        }
    }
}

int solve(int a,int b){
    int k=b-a+1;
    int res=arr[a];
    //cout<<"here is k:"<<k <<endl;
    for(int j=logg;j>=0;j--){
        if(k & (1<<j)){
      //      cout<<"entered j"<<j<<endl;
            res=min(res,rq[a][j]);
            a+=(1<<j);
        }
    }
    return res;
}

int main(){fast();
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    preprocess(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        cout<<solve(a-1,b-1)<<endl;
    }
    return 0;
}