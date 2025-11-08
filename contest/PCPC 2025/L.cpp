
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

vi spf(maxa,-1);

void pre() {
    for (ll i=2;i<maxa;i++) {
        if (spf[i] != -1)continue;
        for (ll j=i;j<maxa;j+=i) {
            spf[j] = i;
        }
    }
}

vector<ii> dec(ll x) {
    vector<ii> res;
    res.reserve(100);
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
set<ll> all_d;

void dfs(ll i,ll curr,vector<ii> &arr){
    ll n=arr.size();
    if (i==n) {
        all_d.insert(curr);
        return ;
    }
    ll mult = 1;
    for (ll occ=0;occ<=arr[i].s;occ++) {
        dfs(i+1,mult*curr,arr);
        mult *= arr[i].f;
    }

}
struct node {
    ll mn,mni,mn2,cnt;
    node() {
        mn=1e9;
        mn2=1e9;
        mni=0;
        cnt=0;
    }
};

int main() {
    fast();
    pre();

    ll n;cin>>n;
    vi arr(n+1),ps(n+1),ss(n+1);
    unordered_map<ll,node> m;
    for (ll i=1;i<=n;i++){
        cin >> arr[i];
        auto fact = dec(arr[i]);
        for (auto d:fact) {
            m[d.f].cnt++;

            if (m[d.f].mn2 <= d.s) continue;
            if (m[d.f].mn <= d.s) {
                m[d.f].mn2 = d.s;
            }
            else {
                m[d.f].mn2 = m[d.f].mn;
                m[d.f].mn = d.s;
                m[d.f].mni = i;
            }
        }
    }

    vi gcdd = arr;
    ps[1] = gcdd[1];
    ss[n] = gcdd[n];
    for (ll i=2;i<=n;i++) {
        ps[i] = gcd(ps[i-1],gcdd[i]);
    }
    for (ll i=n-1;i>=1;i--) {
        ss[i] = gcd(ss[i+1],gcdd[i]);
    }
    gcdd[1] = ss[2];
    gcdd[n] = ps[n-1];
    for (ll i=2;i<=n-1;i++) {
        gcdd[i]  = gcd(ps[i-1],ss[i+1]);
    }

    ll q;
    cin>>q;

    for (ll i=0;i<q;i++) {
        ll a;
        cin>>a;
        if (n==1) {
            cout<<"YES"<<endl;
            continue;
        }
        if (a > (ll)1e7) {
            cout<<"NO"<<endl;
            continue;
        }
        string ans="YES";
        auto fac = dec(a);
        for (auto elem : fac) {
            if (m[elem.f].cnt <= n-2) {
                ans="NO";break;
            }

            if (m[elem.f].mn2 < elem.s) {
                ans="NO";break;
            }
            if (m[elem.f].mn < elem.s) {
                if (gcdd[m[elem.f].mni] % a != 0) {
                    ans="NO";
                }
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
