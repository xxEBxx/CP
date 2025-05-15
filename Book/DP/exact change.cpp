//link:https://vjudge.net/problem/UVA-11517
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
int n,price;
const int maxn=105;
const int maxm=10005;
vector<int> arr(maxn);
vector<vector<ii>> dp(maxn,vector<ii>(maxm,{-1,-1}));

ii solve(int index,int current){
    //cout<<"here is index and c"<<index<<" "<<current<<endl;
    if(current >= price) return {current,0};
    if(index==n)return {1e9,1e9};

    if(dp[index][current].f!=-1)return dp[index][current];

    ii  notake=solve(index+1,current),
        take=solve(index+1,current+arr[index]);
    ii res;
    if(notake.f > take.f){
        res={take.f,take.s+1};
    }
    else if(notake.f < take.f){
        res={notake.f,notake.s};
    }
    else{
        if(notake.s < 1+take.s) res={notake.f,notake.s};
        else res= {take.f,take.s+1};
    }
    return dp[index][current]=res;
}



int main(){fast();
    int t;cin>>t;
    while(t--){
        for(int i=0;i<maxn;i++)for(int j=0;j<maxm;j++)dp[i][j]={-1,-1};
        cin>>price>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ii res=solve(0,0);
        cout<<res.f<<" "<<res.s<<endl;
    }
    return 0;
}

