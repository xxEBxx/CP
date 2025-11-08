
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

string to_bstr(ll x) {
    string s="";
    while (x>0) {
        if (x&1)s+='1';
        else s+='0';
        x>>=1;
    }
    reverse(all(s));
    return s;
}

string d,a,b;
ll vis[32][2][2][2][2],dp[32][2][2][2][2];
ll sz,cnt;
ll solve(ll i,ll smb1,ll bga1,ll smb2,ll bga2) {

    if (i==sz) {
        return 1;
    }
    if (vis[i][smb1][bga1][smb2][bga2] == cnt) {
        return dp[i][smb1][bga1][smb2][bga2];
    }
    ll res = 0;

    if (d[i] == '0') {
        if (a[i]=='1' && (bga1==0 || bga2==0))return 0;
        ll nsmb1=smb1,nbga1=bga1,nsmb2=smb2,nbga2=bga2;
        if (b[i]=='1') {
            nsmb1=1;
            nsmb2=1;
        }
        res = solve(i+1,nsmb1,nbga1,nsmb2,nbga2);
    }
    else {
        //we will try 01 10 11
        //for 01 we make sure x dont go smaller and y dont go bigger
        if ((a[i]=='1' && bga1==0) || (b[i]=='0' && smb2==0)){}
        else {
            ll nsmb1=smb1,nbga1=bga1,nsmb2=smb2,nbga2=bga2;
            if (b[i]=='1') {
                nsmb1=1;
            }
            if (a[i]=='0') {
                nbga2=1;
            }
            res += solve(i+1,nsmb1,nbga1,nsmb2,nbga2);
        }
        //for 10 x dont exceed b and y dont go below b
        if ((b[i]=='0' && smb1==0) || (a[i]=='1' && bga2==0)){}
        else {
            ll nsmb1=smb1,nbga1=bga1,nsmb2=smb2,nbga2=bga2;
            if (b[i]=='1') {
                nsmb2=1;
            }
            if (a[i]=='0') {
                nbga1=1;
            }
            res += solve(i+1,nsmb1,nbga1,nsmb2,nbga2);
        }
        //now for 1 1 we make sure none exceed b
        if (b[i]=='0' && (smb1==0 || smb2==0)){}
        else {
            ll nsmb1 = smb1, nbga1 = bga1, nsmb2 = smb2, nbga2 = bga2;
            if (a[i] == '0') {
                nbga1 = 1;
                nbga2 = 1;
            }
            res += solve(i + 1, nsmb1, nbga1, nsmb2, nbga2);
        }
    }
    vis[i][smb1][bga1][smb2][bga2] = cnt;
    return dp[i][smb1][bga1][smb2][bga2] = res;
}

int main() {
    fast();
    ll t;
    cin >> t;
    memset(vis,-1,sizeof(vis));
    cnt=0;
    while (t--) {
        ll n,l,r;
        cin>>n>>l>>r;
        a = to_bstr(l);
        b = to_bstr(r);

        sz = b.size();
        while (a.size()<b.size()) {
            a = '0'+a;
        }
        ll res=0;
        for (ll i=1;i*i<=n;i++) {

            if (n%i != 0)continue;
            cnt++;
            d = to_bstr(i);
            while (d.size() < b.size()) {
                d = '0'+d;
            }

            if (d.size() <= b.size())
                res += solve(0,0,0,0,0);
            if (i==n/i)continue;

            cnt++;
            d = to_bstr(n/i);
            while (d.size() < b.size()) {
                d = '0'+d;
            }
            if (d.size() <= b.size())
                res+= solve(0,0,0,0,0);
        }
        cout<<res<<endl;
    }
    return 0;
}
