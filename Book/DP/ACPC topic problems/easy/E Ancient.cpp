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
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();

    vvi divisors(maxn);
    for(int i=1;i < maxn;i++){
        for(int j=i;j < maxn;j+=i){
            divisors[j].push_back(i);
        }
    }
    //for(int elem:divisors[28])cout<<elem<<endl;
    vi dp(maxn,1e7);

    dp[1]=0;
    for(int i=2;i < maxn;i++){
        for(int div:divisors[i])dp[i]=min(dp[i],div + dp[i/div]);
        dp[i]=min(dp[i],dp[i-1]+1);
    }

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        ll res=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            res+=dp[arr[i]];
        }
        cout<<res<<endl;
    }
    return 0;
}