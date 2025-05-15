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

string a,b,rule;
int n;
int dp[101][2][2][10];

int solve(int index,int less_b,int higher_a,int before){
    if(index==n)
        return 1;
    if(dp[index][less_b][higher_a][before] != -1){
        return dp[index][less_b][higher_a][before];
    }
    int high,low;
    high=9;
    low=0;
    if(index > 0){
        if(rule[index-1]=='>') {
            if (before == 0)return 0;
            high = before - 1;
        }
        else{
            if (before == 9)return 0;
            low = before + 1;
        }
    }

    if(less_b==0) {
        high = min(b[index] - '0', high);
    }
    if(higher_a==0) {
        low = max(a[index] - '0', low);
    }

    int res=0;
    for(int digit=low;digit<=high;digit++){
        int next_l=less_b,next_h=higher_a;
        if(digit > (a[index]-'0'))next_h=1;
        if(digit < (b[index]-'0'))next_l=1;
        res+=solve(index+1,next_l,next_h,digit);
        res%=mod;
    }
    return dp[index][less_b][higher_a][before]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>a>>b>>rule;
        n=a.size();
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,0,0)<<endl;
    }
    return 0;
}