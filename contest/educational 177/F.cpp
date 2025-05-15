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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;
int x,y,z;
vector<vvi> visited,banned;
int res=0;


void solve(int i,int j,int k){
    if(i>=x || i<0 || j>=y || j<0 || k>=z || k<0)return ;
    if(visited[i][j][k]==1 || banned[i][j][k])return ;

    solve(i+2,j+1,k);
    solve(i-2,j-1,k);
    solve(i-2,j+1,k);
    solve(i+2,j-1,k);

    solve(i+1,j+2,k);
    solve(i+1,j+2,k);
    solve(i+1,j+2,k);


    visited[i][j][k]=1;
}

int main(){fast();
    cin>>x>>y>>z;
    vector<vvi> m(x,vvi(y,vi(z,0))),b=m;
    visited=m;
    banned=b;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a1,b1,c1;cin>>a1>>b1>>c1;
        a1--;b1--;c1--;
        banned[a1][b1][c1]=1;
    }
    return 0;
}