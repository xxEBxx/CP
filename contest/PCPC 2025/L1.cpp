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

const ll maxa = (ll) 1e7 + 1;
const ll mod = (ll) 1e9 + 7;

vi spf(maxa,0);
vi can(maxa,0);
void pre() {
    for (int i = 2; i <= maxa; ++i) {
        if (spf[i] == 0) {                 // i is prime
            spf[i] = i;
            if ((long long)i * i <= maxa) {
                for (int j = i * i; j <= maxa; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
    }
}

vector<ii> dec(ll x) {
    vector<ii> res;
    while(x>1) {
        ll d = spf[x];
        ll cnt=0;
        while (x%d==0) {
            x/=d;
            cnt++;
        }
        res.push_back({d,cnt});
    }
    return res;
}

void dfs(ll i,ll curr,vector<ii> &arr){
    ll n=arr.size();
    can[curr] = 1;
    if (i==n) {
        return ;
    }
    ll mult =1;
    for (ll occ=1;occ<=arr[i].s;occ++) {
        mult *= arr[i].f;
        dfs(i+1,mult*curr,arr);
    }

}

int main() {
    fast();
    pre();

    ll n;cin>>n;
    vi arr(n+1),ps(n+1),ss(n+1);
    for (ll i=1;i<=n;i++){
        cin >> arr[i];
    }

    ps[1] = arr[1];
    ss[n] = arr[n];
    for (ll i=2;i<=n;i++) {
        ps[i] = gcd(ps[i-1],arr[i]);
    }
    for (ll i=n-1;i>=1;i--) {
        ss[i] = gcd(ss[i+1],arr[i]);
    }
    arr[1] = ss[2];
    arr[n] = ps[n-1];
    for (ll i=2;i<=n-1;i++) {
        arr[i]  = gcd(ps[i-1],ss[i+1]);
    }
    sort(all(arr));
    reverse(all(arr));
    for (auto x: arr) {
        if (can[x])continue;
        auto loc = dec(x);
        dfs(0,1,loc);
    }

    ll q;
    cin>>q;

    for (ll i=0;i<q;i++) {
        ll a;
        cin>>a;
        if (can[a] || n==1) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}