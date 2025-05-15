#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

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
string a;
ll dp[19][2],n;

ll solve(ll i,ll lower){
    if(i==n)
        return 1;
    if(dp[i][lower]!=-1)
        return dp[i][lower];
    ll high;
    if(lower==1)
        high=9;
    else
        high=a[i]-'0';

    ll res=0;
    for(ll index=0;index<=high;index++){
        if( (index&1) == (i&1))continue;

        ll next_l=lower;
        if(index < high)next_l=1;
        res+=solve(i+1,next_l);
    }

    return dp[i][lower]=res;
}


int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>a;
    n=a.size();
    ll res=0;
    for(ll i=1;i<= (a[0]-'0');i+=2){
        ll l = 0;
        if((a[0]-'0') > i)l=1;
        res += solve(1, l);
    }
    vector<ll> s(19,0);
    s[1]=(ll)5;
    for(ll i=2;i<=18;i++){
        s[i]=(ll)pow(5,i)+s[i-1];
    }
    //cout<<s[n-1]<<endl;
    cout<<s[n-1]+res<<endl;
    return 0;
}