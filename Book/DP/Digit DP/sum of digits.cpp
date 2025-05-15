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

string a,b;
ll n,dp[10][2][2];

ll solve(int i,int a_bigger,int b_smaller){
    if(i==n)return 0;
    if(dp[i][a_bigger][b_smaller]!=-1)return dp[i][a_bigger][b_smaller];

    int high,low;
    if(a_bigger)low=0;
    else low=a[i]-'0';
    if(b_smaller)high=9;
    else high=b[i]-'0';

    ll res=0;
    for(int index=low;index<=high;index++){
        int na=a_bigger,nb=b_smaller;
        if(index>low)na=1;
        if(index<high)nb=1;
        //cout<<index<<endl;
        res+=index+solve(i+1,na,nb);
    }

    return dp[i][a_bigger][b_smaller]=res;
}

int main(){fast();
    while(cin>>a>>b){
        memset(dp,-1,sizeof(dp));
        if(a=="-1")break;
        while(a.size()<b.size())a.insert(0,"0");
        n=b.size();
        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}