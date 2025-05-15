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

int dp[19][4][2][2],n;
//here we have
string a,b;
int solve(int i,int count,int big_a,int small_b){
    if(count > 3)return 0;
    if(i==n)return 1;

    if(dp[i][count][big_a][small_b]!=-1)return dp[i][count][big_a][small_b];

    int l,r;

    if(big_a)l=0;
    else l=a[i]-'0';

    if(small_b)r=9;
    else r=b[i]-'0';

    int res=0;
    for(int index=l;index<=r;index++){
        int c=count,aa=big_a,bb=small_b;
        if(index!=0)c++;
        if(index > l)aa=1;
        if(index < r)bb=1;
        res+=solve(i+1,c,aa,bb);
    }

    return dp[i][count][big_a][small_b]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;
        n=b.size();
        while(a.size() < b.size())a.insert(0,"0");
        int res=solve(0,0,0,0);
        cout<<res<<endl;
    }
    return 0;
}