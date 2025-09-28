
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

ii dp[10][11][2][2][2];
ll vis[10][11][2][2][2],curr,n;
string a,b;

ii solve(int i, int last, int started, int bga, int smb) {
    if (i == n) return {0,1};
    int li = last + 1;
    if (vis[i][li][started][bga][smb] == curr)
        return dp[i][li][started][bga][smb];

    int low  = bga ? 0 : (a[i]-'0');
    int high = smb ? 9 : (b[i]-'0');
    ii res = {0, 0};

    for (int d = low; d <= high; ++d) {
        int nbga    = bga || (d > low);
        int nsmb    = smb || (d < high);
        int nstarted = started || (d > 0);  // only flip on a real nonzero

        // 1) skip
        ii skip = solve(i+1, last, nstarted, nbga, nsmb);
        if      (skip.f > res.f) res = skip;
        else if (skip.f == res.f) res.s += skip.s;

        // 2) take—but only if this is a “real” digit (nstarted) AND it strictly increases
        if (nstarted && d > last) {
            ii take = solve(i+1, d, nstarted, nbga, nsmb);
            take.f++;
            if      (take.f > res.f) res = take;
            else if (take.f == res.f) res.s += take.s;
        }
    }

    vis[i][li][started][bga][smb] = curr;
    return dp[i][li][started][bga][smb] = res;
}


int main() {
    fast();
    ll t;
    cin >> t;
    curr=0;
    memset(vis,-1,sizeof(vis));

    while (t--) {
        curr++;
        cin>>a>>b;
        while (a.size()<b.size())
            a = '0' + a;
        n = a.size();
        ii res = solve(0,-1,0,0,0);
        cout<<"Case "<<curr<<": "<<res.f<<" "<<res.s<<endl;

    }
    return 0;
}
