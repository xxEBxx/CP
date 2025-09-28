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

string a,b;

ll dp_cnt[20][2][2],n;

ll count_dp(int i, bool bga, bool smb) {
    if (i==n) return 1;
    ll &ans = dp_cnt[i][bga][smb];
    if (ans!=-1) return ans;
    int lo = bga ? 0 : a[i]-'0';
    int hi = smb ? 9 : b[i]-'0';
    ans = 0;
    for (int d = lo; d <= hi; d++) {
        ans += count_dp(i+1, bga | (d>lo), smb | (d<hi));
    }
    return ans;
}

ll dp[10][2][2];
ll solve(ll i,ll bga,ll smb) {
    if (i==n)return 0;
    if (dp[i][bga][smb] != -1)
        return dp[i][bga][smb];
    ll l,h;
    
    if (bga) l=0;
    else l=a[i]-'0';

    if (smb)h=9;
    else h=b[i]-'0';
    ll res=0;
    for (ll index = l;index<=h;index++) {
        ll nbga=bga,nsmb=smb;
        if (index > l)nbga=1;
        if (index < h)nsmb=1;

        res += index*count_dp(i+1,nbga,nsmb) + solve(i+1,nbga,nsmb);
    }
    return dp[i][bga][smb]=res;
}


int main() {
    fast();
    while (cin>>a>>b) {
        if(a=="-1")break;
        while (a.size()<b.size())
            a = '0'+a;
        n=a.size();
        ll res=0;

        memset(dp,-1,sizeof(dp));
        memset(dp_cnt,-1,sizeof(dp_cnt));

        res += solve(0,0,0);
        cout<<res<<endl;
    }
    return 0;
}
