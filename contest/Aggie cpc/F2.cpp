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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

string b,s;
int n,m;

vvi dp(501,vi(501,-1));

int solve(int i,int j){
    if(j==m && i>=n-1)
        return 1;
    if(i>=n)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int res = 0;

    if(b[i]==s[j]){
        res += solve(i+1,j+1);
        res%=mod;
    }
    if(i < n-1 && b[i+1]==s[j]){
        res += solve(i+2,j+1);
        res%=mod;
    }
    return dp[i][j]=res;
}



int main(){fast();
    cin>>b>>s;
    n=b.size();
    m=s.size();

    cout<<solve(0,0)<<endl;

    return 0;
}