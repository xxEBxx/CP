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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=10007;

int main(){fast();
    vi dp(maxn,1e9);
    for(int i=1;i*i<=maxn;i++){
        dp[i*i]=1;
    }
    for(int i=2;i<maxn;i++){
        for(int j=1;j<i;j++){
            dp[i]=min(dp[i],dp[j]+dp[i-j]);
        }
    }

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}