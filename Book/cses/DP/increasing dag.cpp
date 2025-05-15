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
ll n,dp[maxn][10];
string word;

ll solve(ll i,ll digit){
    //digit means the last digit we had at i-1
    if(i==n)
        return 1;
    if(word[i] != '-'){
        if(digit > (word[i]-'0'))
            return 0;

        return solve(i+1,word[i]-'0');
    }
    if(dp[i][digit]!=-1)return dp[i][digit];

    ll res=0;
    for(ll index=digit;index<=9;index++){
        res+=solve(i+1,index);
        res%=mod;
    }
    return dp[i][digit]=(ll)res;
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        cin>>n;
        cin>>word;
        memset(dp,-1,sizeof(dp));
        ll res=0;
        if(word[0]=='-'){
            for(ll i=1;i<=9;i++) {
                res += solve(1,i);
                res%=mod;
            }
        }
        else{
            res=solve(1,word[0]-'0');
        }
        cout<<res<<endl;
    }
    return 0;
}