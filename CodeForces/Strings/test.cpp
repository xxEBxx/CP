#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int n;cin>>n;
    vector<ll> card(maxn),dp(maxn);
    for(int i=0;i<n;i++){
        int val;cin>>val;
        card[val]++;
    }
    dp[0]=0,dp[1]=card[1];
    for(int i=2;i<maxn;i++){
        dp[i]=max(dp[i-1],dp[i-2]+card[i]*i);
    }
    cout<<dp[maxn-1];
    return 0;
}