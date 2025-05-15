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

const int maxn=(int)103;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,m;
vector<vector<vector<ll>>> b(maxn,vvl (maxn,vl (maxn,0))),
                            arr(maxn,vvl (maxn,vl (maxn,0)));
ll gett(ll x,ll y,ll z){
    if(x>n || y>n || z>n)return gett(n,n,n);
    ll res=0;
    while(z>0){
        ll yy=y;
        while(yy>0){
            ll xx=x;
            while(xx>0){
                res += b[xx][yy][z];
                xx-=xx&-xx;
            }
            yy-=yy&-yy;
        }
        z -= z & -z;
    }
    return res;
}


void sett(ll i ,ll j,ll z,ll v){
    //cout<<"here is set ;";
    ll diff = v - arr[i][j][z];
    arr[i][j][z]=v;
    while(z <= n){
        ll ii=i;
        while (ii <= n) {
            ll jj=j;
            while (jj <= n) {
                b[ii][jj][z] += diff;
                jj += jj & -jj;
            }
            ii += ii & -ii;
        }
        z+=z&-z;
    }
}

int main(){
    cin>>n>>m;n++;
    for(int i=0;i<m;i++){
        int q;cin>>q;
        if(q==1){
            ll x,y,z,val;cin>>x>>y>>z>>val;
            sett(x+1,1+y,1+z,val);
        }
        else{
            ll x,y,z,X,Y,Z;cin>>x>>y>>z>>X>>Y>>Z;
            cout<<gett(n,n,n)-gett(X+1,1+Y,1+Z)-gett(1+x,1+y,1+z)<<endl;
        }
    }
    return 0;
}
