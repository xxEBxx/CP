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

//we need to minimize the max distance in a way
//when 2 choices choose min between the 2 and answer is max between this key and the answer from the 2

int dp[1001][2001],n,k,p;
vi arr,keys;
//here the people are the ones that should be taken all not the keys
int solve(int i,int taken){
    if(i==n)return 0;
    if(k==taken) return -2;

    if(dp[i][taken]!=-1)return dp[i][taken];

    int take=solve(i+1,taken+1);
    if(take!=-2)take=max(take,abs(keys[taken]-arr[i]) + abs(keys[taken]-p));

    int notake=solve(i,taken+1);

    int res=min(take,notake);
    if(take==-2)res=notake;
    if(notake==-2)res=take;

    return dp[i][taken]=res;
}


int main(){fast();
    cin>>n>>k>>p;
    arr.resize(n);
    keys.resize(k);

    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<k;i++)cin>>keys[i];
    memset(dp,-1,sizeof(dp));
    sort(all(arr));
    sort(all(keys));
    cout<<solve(0,0)<<endl;


    return 0;
}