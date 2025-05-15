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

#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll n;
vi st(4*maxn,0ll),arr(maxn,0ll);
//in general the st array only get 2 times size of arr
//but to be sure we use 4
void build(ll i,ll l,ll r){
    if(l==r)st[i]=1e16;
    else{
        ll mid=M(l,r);
        build(L(i),l,mid);
        build(R(i),mid+1,r);
        st[i]=min(st[R(i)],st[L(i)]);
    }
}


ll query(ll a,ll b, ll id,ll l,ll r){
    if(b<l || a>r)return 1e9 +3;
    if(a<=l && b>=r)return st[id];
    ll mid=M(l,r);
    return min(
            query(a,b,L(id),l,mid),
            query(a,b,R(id),mid+1,r)
    );


}
void update(ll id,ll l ,ll r, ll i,ll v){
    if(l==r)st[id]=arr[l]=v;
    else{
        ll mid=M(l,r);
        if(i<=mid)update(L(id),l,mid,i,v);
        else update(R(id),mid+1,r,i,v);
        st[id]=min(st[R(id)],st[L(id)]);
    }
}


int main(){fast();
    int t;cin>>t;
    while(t--){
        cin >> n;
        vector<ll> ps(n + 1, 0), dp(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            ps[i] = arr[i] + ps[i - 1];
        }
        build(1, 1, n);
        update(1, 1, n, 1, arr[1]);
        //in the st we will store the dp's
        for (ll i = 2; i <= n; i++) {
            dp[i] = query(1, i - 1, 1, 1, n);
            update(1, 1, n, i, dp[i]);
        }
        for(int i=1;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        cout << dp[n] << endl;
    }

    return 0;
}
