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

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

#define M(i,j) ((i+j)>>1)
#define L(i) (i<<1)
#define R(i) ((i<<1)+1)

int st[maxn*3],arr[maxn];

void build(int id,int l,int r){
    if(l==r)
        st[id]=arr[l];
    else {
        //we need to build the son's
        int m=M(l,r);
        build(L(id),l,m);
        build(R(id),m+1,r);
        st[id] = st[L(id)] ^ st[R(id)];
    }
}

int get(int id,int l,int r,int x,int y){
    //i want elements from x to y
    if(x > r || l > y)return 0;
    if(x <= l && r <= y)return st[id];

    int mid=M(l,r);
    int a=get(L(id),l,mid,x,y);
    int b=get(R(id),mid+1,r,x,y);

    return a^b;
}

int main(){fast();
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(q--){
        int a,b;cin>>a>>b;
        cout<<get(1,1,n,a,b)<<endl;
    }

    return 0;
}