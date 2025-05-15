#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll n,m;cin>>m>>n;
    vector<ll> s(m+1,0),l(m+1,0);
    for(ll i=1;i<=m;i++){
        cin>>s[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>l[i];
    }
    vector<vi> dp(n+1,vi(m+1,0));
    dp[0][1]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
//dp[i][j] is the number of possible way to come to j from day i-1
            for(ll k=1;k<=m;k++){
                ll coeff = l[k]*s[j]+s[k]*s[j]+s[k]*l[j];
                dp[i][j] += coeff * dp[i-1][k];
                dp[i][j] %= mod;
            }

        }
    }
    ll res=0;
    for(ll i=1;i<=m;i++){
        res+=dp[n][i];
        res%=mod;
    }
    cout<<res<<endl;

    return 0;
}