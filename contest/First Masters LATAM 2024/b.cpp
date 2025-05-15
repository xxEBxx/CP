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
int dp[20][2][3],n;

int solve(int i,int smaller,int smaller2){
    if(i==n)return 1;
    if(dp[i][bigger_a][smaller_b]!=-1)return dp[i][bigger_a][smaller_b];

    int low,high;
    if(bigger_a)low=0;
    else low=a[i]-'0';
    if(smaller_b)high=9;
    else high=b[i]-'0';
    int res=0;
    for(int index=low;index<=high;index++){
        int na=bigger_a,nb=smaller_b;
        if(index > low)na=1;
        if(index < high)nb=1;
        res+=solve(i+1,na,nb);
    }
    return dp[i][bigger_a][smaller_b]=res;
}


int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>a>>b;
        while(b.size() > a.size())a.append(0,'0');
        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}