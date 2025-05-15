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

const int maxn=(int)1e5 *2 +7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
int n,m;
vi st(4*maxn,0),arr(maxn,0);
//in general the st array only get 2 times size of arr
//but to be sure we use 4
void build(int i,int l,int r){
    if(l==r)st[i]=arr[l];
    else{
        int mid=M(l,r);
        build(L(i),l,mid);
        build(R(i),mid+1,r);
        st[i]=min(st[R(i)],st[L(i)]);
    }
}

int query(int a,int b, int id,int l,int r){
    if(b<l || a>r)return 1e9 +3;
    if(a<=l && b>=r)return st[id];
    int mid=M(l,r);
    return min(
            query(a,b,L(id),l,mid),
            query(a,b,R(id),mid+1,r)
            );

}
void update(int id,int l ,int r, int i,int v){
    if(l==r)st[id]=arr[l]=v;
    else{
        int mid=M(l,r);
        if(i<=mid)update(L(id),l,mid,i,v);
        else update(R(id),mid+1,r,i,v);
        st[id]=min(st[R(id)],st[L(id)]);
    }
}

int main(){fast();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    for(int i=0;i<m;i++){
        int q,a,b;cin>>q>>a>>b;
        if(q==1)update(1,1,n,a,b);
        else cout<<query(a,b,1,1,n)<<endl;
    }

    return 0;
}