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
const ll mod = 2520 ;

ll k,dp[18][1<<10][mod];
vi dig ;

// we try reversing to not care about trailing zeros
// to not care about both smaller and bigger
// then remove last bigger and
ll solve(ll i,ll bitmask,ll rest,bool thight) {
    if (i==-1) {
        //we see all digits that exist and see if divisible
        ll cnt=0;
        for (ll d=1;d<10;d++) {
            if ((bitmask>>d & 1) && rest%d==0)
                cnt++;
        }
        return cnt >= k;
    }

    if (!thight && dp[i][bitmask][rest] != -1)
        return dp[i][bitmask][rest];

    ll h;
    if (!thight)h=9;else h=dig[i];

    ll res=0;

    for (ll index = 0;index<=h;index++) {
        ll nb = bitmask,nrest= (10*rest+index)%mod, ntight = thight ;
        if (index<h)thight=false;

        nb |= (1<<index);
        res += solve(i-1,nb,nrest,ntight);
    }
    if (!thight) { dp[i][bitmask][rest] = res; }
    return res;

}

ll count_le(long long x) {
    dig.clear();
    while (x) { dig.push_back(x%10); x/=10; }
    if (dig.empty()) dig.push_back(0);
    return solve((ll)dig.size()-1, 0, 0, true);
}

ll find(long long a, long long b) {
    return count_le(b) - count_le(a-1);
}



int main() {
    fast();
    ll t;
    cin >> t;


    while (t--) {
        memset(dp,-1,sizeof dp);
        ll a,b;
        cin>>a>>b>>k;
        cout<<find(a,b)<<endl;
    }
    return 0;
}
