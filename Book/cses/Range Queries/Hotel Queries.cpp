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
int arr[maxn],st[maxn*3];

#define M(i,j) ((i+j)>>1)
#define L(i) (i<<1)
#define R(i) ((i<<1)+1)

void build(int id,int l,int r){
    if(l==r)st[id]=arr[l];
    else{
        int mid=M(l,r);
        build(L(id),l,mid);
        build(R(id),mid+1,r);
        st[id]=max(st[L(id)],st[R(id)]);
    }
}

int query(int id,int l,int r,int k){
    if(k > st[id])return 0;
    if(l==r && st[id]>=k)return l;

    if(st[L(id)] >= k)
        return query(L(id),l,M(l,r),k);
    return query(R(id),M(l,r)+1,r,k);
}

void update(int id,int l,int r,int index,int k){
    //you need to minus it by a
    if(k > st[id])return ;
    if(l==r && r==index)st[id]-=k;
    else{
        if(st[L(id)] >= k)
            update(L(id),l,M(l,r),index,k);
        else update(R(id),M(l,r)+1,r,index,k);
        st[id]=max(st[L(id)],st[R(id)]);
    }
}

int main(){fast();
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(q--){
        int a;cin>>a;
        int res=query(1,1,n,a);
        cout<<res<<" ";
        update(1,1,n,res,a);
    }
    return 0;
}