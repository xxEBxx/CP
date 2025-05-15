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

const int maxn=2002;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

string a,b;
int dp[maxn][maxn][2][2],m,d,n;
//first state is index so far , second is the remainder (needs to be 0 at the end):

int solve(int i,int remainder,int a_bigger,int b_smaller){
    if(i==n)return remainder==0;
    if(dp[i][remainder][a_bigger][b_smaller]!=-1)return dp[i][remainder][a_bigger][b_smaller];

    int res=0;

    int low,high;
    if(a_bigger)low=0;
    else low=a[i]-'0';
    if(b_smaller)high=9;
    else high=b[i]-'0';

    if(i & 1){
        if(d<=high && d>=low){
            int nrm,na=a_bigger,nb=b_smaller;
            if(d>low)na=1;
            if(d<high)nb=1;
            nrm=remainder*10+d;
            nrm%=m;
            res+=solve(i+1,nrm,na,nb);
            res%=mod;
        }
    }
    else{
        //we dont take the d;
        for(int index=low;index<=high;index++){
            if(index==d)continue;
            int nrm,na=a_bigger,nb=b_smaller;
            if(index>low)na=1;
            if(index<high)nb=1;
            nrm=remainder*10+index;
            nrm%=m;
            res+=solve(i+1,nrm,na,nb);
            res%=mod;
        }
    }
    return dp[i][remainder][a_bigger][b_smaller]=res;
}
int main(){fast();
    cin>>m>>d;
    cin>>a>>b;

    n=a.size();
    //cout<<n<<endl;

    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0,0);
    return 0;
}