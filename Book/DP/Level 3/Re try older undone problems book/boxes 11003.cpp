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

const int maxn= 1002;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

// we need to know the maximum weight we could have , it is min of n-1 and nth one
//index and available ?

int av[maxn],n,w[maxn],dp[maxn][3003];

int solve(int i,int to_lift){
    if(i==n)return 0;
    if(dp[i][to_lift]!=-1)return dp[i][to_lift];

    int res=solve(i+1,to_lift);//not taking
    if(to_lift >= w[i]){//means we can take the element
        res=max(res,
                1+solve(i+1,min(av[i],to_lift-w[i]))
                );
    }
    return dp[i][to_lift]=res;
}

int main(){fast();
    while(cin>>n){
        memset(dp,-1,sizeof(dp));
        if(n==0)break;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>w[i]>>av[i];
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res=max(res,1+solve(i+1,av[i]));
            //this means that first element taken is i;
        }
        cout<<res<<endl;
    }
    return 0;
}