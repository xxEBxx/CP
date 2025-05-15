#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct node {
    vi arr;
    ll res = 0;
};
node unit = {vi(41,0) , 0};

struct Tree {
    typedef node T;
    node f(node a, node b) {
        ll here = 0,counter=0;
        vi res_arr(41,0);
        for(ll i=1;i<41;i++){
            res_arr[i] += a.arr[i] + b.arr[i];
            here += counter * a.arr[i];
            counter += b.arr[i];
        }

        return {res_arr ,a.res + b.res +here };
    }
    vector<T> s; ll n;
    Tree(ll n = 0, T def = unit ) : s(2*n, def), n(n) {}
    void update(ll pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(ll b, ll e) { // query [ b , e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};



int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n,q;cin>>n>>q;
    Tree st(1e5+2);

    for(ll i=1;i<=n;i++){
        ll val;cin>>val;
        vi arr(41,0);
        arr[val]=1;
        st.update(i,{arr,0});
    }

    for(ll i=0;i<q;i++){
        ll a;cin>>a;
        if(a==2){
            ll index,val;cin>>index>>val;
            vi arr(41,0);
            arr[val]=1;
            st.update(index,{arr,0});
        }
        else{
            ll l,r;cin>>l>>r;
            cout<<st.query(l,r+1).res<<endl;
        }
    }

}