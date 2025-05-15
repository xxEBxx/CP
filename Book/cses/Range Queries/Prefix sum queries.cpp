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

const ll maxn=(ll)1e5*2+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
#define M(i,j) ((i+j)>>1)
#define L(i) (i<<1)
#define R(i) ((i<<1)+1)

ll st_prefix[maxn*4],st[maxn*4],arr[maxn];

void merge(ll id){
    st[id]=max(st[L(id)],
               st_prefix[L(id)]+st[R(id)]);
    st_prefix[id]=st_prefix[L(id)]+st_prefix[R(id)];
}

void build(ll id,ll l,ll r){
    if(l==r) { st[id] = st_prefix[id] =arr[l]; return ;}
    ll mid=M(l,r);
    build(L(id),l,mid);
    build(R(id),mid+1,r);
    merge(id);
}

void update(ll id,ll l,ll r,ll index,ll value){
    if(r<index || l>index )return;
    if(l==r && l==index){
        st[id]=st_prefix[id]=value;
        return;
    }
    ll mid=M(l,r);
    update(L(id),l,mid,index,value);
    update(R(id),mid+1,r,index,value);
    merge(id);
}

ii query(ll id,ll l,ll r,ll a,ll b){
    if(l>b || r<a)return {0,0};
    if(a<=l && r<=b)return {st[id],st_prefix[id]};
    ll mid=M(l,r);
    ii left= query(L(id),l,mid,a,b);
    ii right= query(R(id),mid+1,r,a,b);

    return {max(left.f,left.s+right.f)
            ,left.s+right.s};
}


int main(){fast();
    ll n,q;cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    while(q--){
        ll t,a,b;cin>>t>>a>>b;
        if(t==1){
            update(1,1,n,a,b);
        }
        else{
            cout<<max((ll)0,query(1,1,n,a,b).f)<<endl;
        }
    }
    return 0;
}