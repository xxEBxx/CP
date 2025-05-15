//link : https://vjudge.net/problem/UVA-10306
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

const int maxn=(int)1e6+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        getchar();
        int n,mod;
        cin >> n >> mod;
        int MOD=mod*mod;
        vi mon(n),emon(n);
        for (int i = 0; i < n; i++) {
            cin >> mon[i] >> emon[i];
        }
        vvi dp(mod+1,vi(mod+1,1e9));
        dp[0][0]=0;
        for(int i=0;i<mod+1;i++){
            for(int j=0;j<mod+1;j++){
                for(int k=0;k<n;k++){
                     if(i>=mon[k] && j>=emon[k]){
                         dp[i][j]=min(dp[i][j],
                                      1+dp[i-mon[k]][j-emon[k]]);
                     }
                }
            }
        }
        int res=1e9;
        for(int i=0;i<=mod;i++){
            int j=sqrt(MOD-i*i);
            if(i*i+j*j==MOD)res=min(res,dp[i][j]);
        }

        if (res == 1e9)cout << "not possible" << endl;
        else cout << res << endl;

    }
    return 0;
}