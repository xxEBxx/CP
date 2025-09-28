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
const ll mod =  998244353;


string s;

ll c,n;
ll dp_cnt[18][1<<10][2][2];

ll count_way(ll i,ll bitmask,ll sma,ll z) {
    if (__builtin_popcount(bitmask) > c)
        return 0;
    if (i == n)return 1;
    if (dp_cnt[i][bitmask][sma][z] != -1)
        return dp_cnt[i][bitmask][sma][z];

    ll h;
    if (sma)h=9;
    else h = s[i]-'0';
    ll res = 0;

    for (ll index=0;index<=h;index++) {
        ll nbitmask =bitmask,nsma=sma,nz =z;
        if (index != 0 || z)
            nbitmask |= (1<<index);
        //dont count trailing zeros as elemeents of the array
        if (index < h)nsma =1;
        if (index != 0)nz=1;

        res += count_way(i+1,nbitmask,nsma,nz);
        res %= mod;
    }
    return dp_cnt[i][bitmask][sma][z] = res;
}


ll dp[18][1<<10][2][2];
ll solve(ll i,ll bitmask,ll sma,ll z) {
    if (__builtin_popcount(bitmask) > c)
        return 0;
    if (i == n)return 0;
    if (dp[i][bitmask][sma][z] != -1)
        return dp[i][bitmask][sma][z];

    ll h;
    if (sma)h=9;
    else h = s[i]-'0';
    ll res = 0;

    for (ll index=0;index<=h;index++) {
        ll nbitmask =bitmask,nsma=sma,nz =z;
        if (index != 0 || z)
            nbitmask |= (1<<index);
        //dont count trailing zeros as elemeents of the array
        if (index < h)nsma =1;
        if (index != 0)nz=1;

        res += (index * ((ll)pow(10ll,n-i-1ll)%mod)%mod) * count_way(i+1,nbitmask,nsma,nz) %mod;
        res += solve(i+1,nbitmask,nsma,nz)%mod;
        res %= mod;
    }
    return dp[i][bitmask][sma][z] = res;
}

int main() {
    fast();
    string a,b;

    cin>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    memset(dp_cnt,-1,sizeof(dp_cnt));
    s = b;
    n=s.size();
    ll res = solve(0,0,0,0);

    memset(dp,-1,sizeof(dp));
    memset(dp_cnt,-1,sizeof(dp_cnt));
    s = a;
    n=s.size();
    res -= solve(0,0,0,0);

    ll bitmask=0,loc=0;
    for (auto c : a) {
        bitmask |= (1<<(c-'0'));
        loc *= 10;
        loc += c-'0';
    }

    if (__builtin_popcount(bitmask) <= c) {
        res += loc;
    }
    while (res<0)res+=mod;
    cout<<res%mod<<endl;
    return 0;
}
