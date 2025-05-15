#include<bits/stdc++.h>

#define all(v) v.begin(), v.r()
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

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int st[4*maxn],lp[4*maxn],arr[maxn];
const int MAX_A=1e4+1;
vector<vector<ll>> prime_factors(MAX_A+1);

void sieve_of_eratosthenes() {
    for (ll i = 2; i <= MAX_A; ++i) {
        if (prime_factors[i].empty()) { // i is a prime number
            for (ll multiple = i; multiple <= MAX_A; multiple += i) {
                prime_factors[multiple].push_back(i);
            }
        }
    }
}

ll get_sum_prime_factor(ll num) {
    if (num == 1) return 0; // 1 has no prime factors
    ll res=0;
    for (auto elem:prime_factors[num]) {
        ll repeat=0;
        while(num%elem==0){
            repeat++;
            num/=elem;
        }
        res+=elem*repeat;
    }
    return res;
}
#define L(i) (i<<1)
#define R(i) ((i<<1)+1)

void build(ll id, ll l, ll r) {
    if (l == r) {
        st[id] = get_sum_prime_factor(arr[l]);
    } else {
        ll mid = (l + r) / 2;
        build(L(id),l,mid);
        build(R(id), mid + 1, r);
        st[id] = st[2 * id + 1] + st[2 * id + 2];
    }
}

void update_one(ll id, ll l, ll r, ll index) {
    if (r == l && l==index){
        if(lp[id]!=-1) {
            arr[l] = lp[id];
            lp[id] = -1;
            st[id]= get_sum_prime_factor(arr[l]);
        }
        ll prime_factor;
        if (arr[index] > 1) {
            // Remove the last prime factor for simplicity
            prime_factor = prime_factors[arr[index]].back();
            arr[index] /= prime_factor;
        }
        st[id] -= prime_factor;

    } else {
        ll mid = (l +r) / 2;
        if(lp[id]!=-1)lp[L(id)] = lp[id];
        if(lp[id]!=-1)lp[R(id)] = lp[id];
        lp[id] = -1;

        if (l <= index && index <= mid) {
            update_one(L(id),l,mid,index);
        } else {
            update_one(R(id),mid+1,r,index);
        }

        st[id]=st[L(id)]+st[R(id)];
    }
}

void update_range(ll id,ll l,ll r,ll a,ll b,ll x){
    if(l==r){
        lp[id]=x;

        return;
    }
    if(l<=a && b<=r) {
        lp[id] = x;
        return;
    }
    if(b<l || r<a)
        return;

    ll mid=(l+r)/2;
    update_range(L(id),l,mid,a,b,x);
    update_range(R(id),mid+1,r,a,b,x);

}

ll query(ll id,ll l,ll r,ll a,ll b){
    if(l>b || r<a)
        return 0;
    if(a<=l && r<=b){
        if(lp[id] != -1) {
            return (l-r+1)* get_sum_prime_factor(lp[id]);
        }
        return st[id];
    }
    ll mid = (l +r) / 2;
    if(lp[id]!=-1)lp[L(id)] = lp[id];
    if(lp[id]!=-1)lp[R(id)] = lp[id];
    lp[id] = -1;

    ll aa = query(L(id),l,mid,a,b);
    ll bb = query(R(id),mid+1,r,a,b);

    return st[id]=aa+bb;
}


int main(){fast();
    sieve_of_eratosthenes();
    memset(lp,-1,sizeof(lp));
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
    ll q;cin>>q;
    for(int i=1;i<=q;i++){
        int t;cin>>t;
        if(t==1){
            ll index;cin>>index;
            update_one(1,1,n,index);
        }
        else if(t==2){
            ll l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
        else{
            ll l,r,x;cin>>l>>r>>x;
            update_range(1,1,n,l,r,x);
        }
    }
    return 0;
}