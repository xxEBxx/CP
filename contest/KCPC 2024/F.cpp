
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

ll k,cnt,dp[70][2][2][70][2],vis[70][2][2][70][2];
string st,en;

ll solve(ll i,ll smb,ll bga,ll curr,ll ended) {
    if (i==st.size())
        return ended || curr==k;

    if (vis[i][smb][bga][curr][ended]==cnt) {
        return dp[i][smb][bga][curr][ended];
    }
    ll res=0;

    ll l,h;
    if (bga)l=0;
    else l = st[i]-'0';
    if (smb)h=1;
    else h = en[i]-'0';

    for (ll index = l;index<=h;index++) {
        ll nsmb=smb,nbga=bga,ncurr=0,nended=ended;

        if (index==1)ncurr=curr+1;
        if (index < (en[i]-'0'))nsmb=1;
        if (index > (st[i]-'0'))nbga=1;
        if (curr == k)nended=1;
        res+=solve(i+1,nsmb,nbga,ncurr,nended);
    }


    vis[i][smb][bga][curr][ended]=cnt;
    return dp[i][smb][bga][curr][ended] = res;;
}

int main() {
    fast();
    ll t;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    memset(vis,-1,sizeof(vis));
    cnt=0;
    while (t--) {
        cnt++;
        ll a,b;
        cin>>a>>b>>k;
        st = en = "";
        while (a > 0) {
            st += (char)('0' + a%2);
            a/=2;
        }
        while (b > 0) {
            en += (char)('0' + b%2);
            b/=2;
        }

        reverse(all(st));
        reverse(all(en));
        while (st.size() < en.size()) {
            st = '0' + st;
        }

        cout<<solve(0,0,0,0,0)<<endl;
    }
    return 0;
}
