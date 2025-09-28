
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;


struct Tree {
    typedef ll T;
    static constexpr T unit = 0 ;
    T f(T a, T b) { return (a+b)%mod; } // (any associative fn)
    vector<T> s; ll n;
    Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(ll pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(ll b, ll e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

const ll maxa = (ll)1e6+2;
ll facto[maxa],inv_facto[maxa];
ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a)
    % mod;
}
void pre() {
    facto[0]=1;
    for (ll i=1;i<maxa;i++) {
        facto[i] = facto[i-1]*i;
        facto[i]%=mod;
    }

    inv_facto[maxa-1] = inv(facto[maxa-1]);
    for (ll i=maxa-2;i>=0;i--) {
        inv_facto[i] = inv_facto[i+1] * (i+1);
        inv_facto[i] %= mod;
    }

}

ll c(ll k,ll n) {
    if (k < 0 || k > n) return 0;
    ll res = facto[n];
    res *= inv_facto[n-k];
    res %= mod;
    res *= inv_facto[k];
    res %= mod;
    return res;
}

int main() {

    fast();
    ll n;
    pre();
    //cout<<c(3,4)<<endl;
    cin>>n;
    vi arr(n+1,0);
    vector<Tree> st(20,Tree(n+1));//one segemnt tree for each bit

    for (ll i=1;i<=n;i++) {
        cin>>arr[i];
        for (ll j=0;j<20;j++) {
            if (arr[i]>>j & 1) {
                st[j].update(i,1);
            }
        }
    }
    ll q;
    cin>>q;
    for (ll i=0;i<q;i++) {
        ll a;
        cin>>a;
        if (a==1) {
            ll l,r,k;
            cin>>l>>r>>k;
            ll res=0;
            for (ll j=0;j<20;j++) {
                //ways to take 0 on bit
                ll cnt = st[j].query(l,r+1),d=r-l+1;
                ll invalid = c(k,d-cnt);
                ll ways  = c(k,d);
                ways-=invalid;
                if (ways<0) ways += mod;
                ll loc = ((1ll<<j) * ways)%mod;
                res += loc;
                res %= mod;
            }
            cout<<res<<endl;
        }
        else {
            ll index,val;
            cin>>index>>val;
            for (ll j=0;j<20;j++) {
                if (val>>j & 1)
                    st[j].update(index,1);
                else
                    st[j].update(index,0);
            }
        }
    }


    return 0;
}
