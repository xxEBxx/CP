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

string s,before;

ll dp[15][2][2][2],vis[15][2][2][2],cnt;
ll sz;
ll solve(ll i,ll smaller,ll f,ll se) {

    if (i==sz)
        return f==1 && se==1;

    if (vis[i][smaller][f][se] == cnt) {
        return dp[i][smaller][f][se];
    }

    ll h;

    if (smaller)h=9;
    else h=s[i]-'0';

    ll res=0;
    for (ll index = 0;index<=h;index++) {
        ll nsmaller = smaller,nf = f,nse = se;
        if (index < h)nsmaller = 1;
        if (index==4)nf=1;
        if (index==7)nse=1;

        res += solve(i+1,nsmaller,nf,nse);
    }
    vis[i][smaller][f][se]=cnt;
    return dp[i][smaller][f][se] = res;
}
ll n;
bool work(long long x){
    //find minimum x that lets us have
    //x - bad of x  = n
    s = to_string(x);
    sz = (long long)s.size();
    cnt++;
    long long bad = solve(0, 0, 0, 0);
    return (x - bad) >= n;
}


int main() {
    fast();
    ll t;
    cin >> t;
    cnt = 0;
    memset(vis,-1,sizeof(vis));
    while (t--) {

        cin >> n;
        s = to_string(n);

        ll mn=n,mx=1e15-2;

        while (mn+1 < mx) {
            ll middle = (mn+mx)/2;
            if (work(middle))
                mx = middle;
            else
                mn = middle;
        }
        if (work(mn))cout<<mn<<endl;
        else cout<<mx<<endl;
    }
    return 0;
}

