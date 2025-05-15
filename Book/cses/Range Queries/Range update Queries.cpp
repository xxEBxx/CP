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

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

#define M(i,j) ((i+j)>>1)
#define L(i) (i<<1)
#define R(i) ((i<<1)+1)

ll st[3*maxn],arr[maxn],to_add[3*maxn];

void build(ll id,ll l,ll r){
    if(l==r)st[id]=arr[r];
    else{
        ll mid=M(l,r);
        build(L(id),l,mid);
        build(R(id),mid+1,r);
        st[id] = st[R(id)]+st[L(id)];
    }
}

void lower(int id){
    to_add[L(id)] += to_add[id];
    to_add[R(id)] += to_add[id];
    to_add[id]=0;
}

ll get(ll id,ll l,ll r,ll k){
    if(l==r && r==k)return st[id]+to_add[id];
    if(r<k || l>k)return 0;
    ll mid=M(l,r);
    lower(id);
    ll a=get(L(id),l,mid,k);
    ll b=get(R(id),mid+1,r,k);
    return a+b;
}

void update(ll id,ll l,ll r,ll a,ll b,ll u){
    if(a>r || b<l)return ;
    if(a<=l && r<=b){
        to_add[id] += u;
        return;
    }
    ll mid=M(l,r);
    update(L(id),l,mid,a,b,u);
    update(R(id),mid+1,r,a,b,u);
}

int main(){fast();
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(q--){
        ll t;cin>>t;
        if(t==1){
            ll a,b,u;cin>>a>>b>>u;
            update(1,1,n,a,b,u);
        }
        else{
            ll k;cin>>k;
            cout<<get(1,1,n,k)<<endl;
        }
    }
    return 0;
}