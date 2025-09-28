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

string s;
ll curr,n,dp[19][1<<9][10][2][2],vis[19][1<<9][10][2][2];
ll solve(ll i, ll bitmask, ll max_far,ll smb,ll tz) {
    if (i == n)
        return __builtin_popcount(bitmask) == max_far;
    if (vis[i][bitmask][max_far][smb][tz] == curr)
        return dp[i][bitmask][max_far][smb][tz];

    ll h;
    if (smb)h=9;
    else h = s[i]-'0';
    ll res=0;
    for (ll index =0;index<=h;index++) {
        ll nsmb =smb,nbitmask=bitmask,nmax_far=max(max_far,index),ntz=tz;
        if (index < h)nsmb=1;
        if (index>0 || tz==0)nbitmask |= (1<<index);
        if (index > 0)ntz=0;
        res += solve(i+1,nbitmask,nmax_far,nsmb,ntz);
    }
    vis[i][bitmask][max_far][smb][tz] = curr;
    return dp[i][bitmask][max_far][smb][tz] = res;
}

int main() {
    fast();
    ll t;
    cin >> t;

    while (t--) {
        curr++;
        cin>>s;
        n=s.size();
        cout<<solve(0ll,0ll,0ll,0ll,1ll)-1ll<<endl;

    }
    return 0;
}
