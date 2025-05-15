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
#define M(i,j) ((i+j)>>1)
#define L(i) (i>>1)
#define R(i) ((i>>1)+1)

int arr[maxn],st[maxn*3],to_add[maxn*3],to_set[maxn*3];

void build(int id,int l,int r){
    if(l==r)st[id]=arr[l];
    else{
        int mid=M(l,r);
        build(L(id),l,mid);
        build(R(id),mid+1,r);
        st[id] = st[L(id)]+st[R(id)];
    }
}

void update_set(int id,int l,int r,int a,int b,int value){
    if(a<=l && r<=b){
        to_set[id]=value;
        to_add[id]=0;
        return ;
    }
    int mid=M(l,r);

    to_add[R(id)] += to_add[id];
    to_add[L(id)] += to_add[id];

    update_set(L(id),l,mid,a,b,value);
    update_set(R(id),mid+1,r,a,b,value);
}

void update_add(int id,int l,int r,int a,int b,int x){
    if(a<=l && r<=b){
        to_add[id] += x;
        return;
//we don't remove the set because set happened before the increase
    }
    int mid=M(l,r);
    update_add(L(id),l,mid,a,b,x);
    update_add(R(id),mid+1,r,a,b,x);


}

int query(int id,int l,int r,int a,int b){
    if(a<=l && r<=b){
        if(to_set[id]>0){
            return to_set[id]*(r-l+1)+to_add[id];
        }
        return st[id]*(r-l+1)+to_add[id];
    }
    int mid=M(l,r);

    if(to_set[id]>0){
        to_set[L(id)]
    }


}

int main(){fast();
    memset(to_set,-1,sizeof(to_set));
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];

    }
    return 0;
}