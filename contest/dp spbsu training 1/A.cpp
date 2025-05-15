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

const int maxn=102;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dp[maxn][maxn][maxn][maxn];
int n1,n2,n3,k;

int solve(int index,int n1,int n2,int n3){
    if(n1==0 && n2==0 && n3==0)return 0;

}

int main(){fast();
    cin>>n1>>n2>>n3;
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;

    return 0;
}