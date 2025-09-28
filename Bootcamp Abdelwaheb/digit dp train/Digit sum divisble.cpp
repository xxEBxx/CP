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

ll dp[15][130][130],vis[15][130][130],curr,n,mod;
string a;
ll solve(ll i,ll sum,ll rem,ll lo) {
    if (i==n)
        return mod==sum && rem==0;

    if (lo && vis[i][sum][rem] == curr)
        return dp[i][sum][rem];

    ll h;
    h  =lo ?9:a[i]-'0';
    ll res=0;
    for (ll index =0;index<=h;index++) {
        ll nsum = sum + index;
        ll nrem = rem*10+index;
        nrem %= mod;

        res+= solve(i+1,nsum,nrem,lo | (index<h));
    }
    if (lo) {
        vis[i][sum][rem] = curr;
        dp[i][sum][rem] = res;
    }
    return res;
}

int main() {
    fast();
    cin>>a;
    n=a.size();
    curr=0;
    ll res=0;
    memset(vis,-1,sizeof(vis));
    for (ll i =1 ;i<127;i++) {
        curr++;
        mod = i;
        res += solve(0,0,0,0);
    }
    cout<<res;

    return 0;
}
