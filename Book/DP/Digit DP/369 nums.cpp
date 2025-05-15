#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int ,int > ii;
typedef pair<ll,ll> pl;
typedef vector<int > vi;
typedef vector<vector<int >> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int  maxn=(int )1e6+7;
const int  mod=(int )1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

string a,b;
int n,dp[51][35][35][2][2][2];

int solve(int  i,int  ts,int  sn,int  done,int  a_bigger,int  b_smaller){
    if(i==n){
        if(done==1 && ts==17 && sn==17)return 1;
        return 0;
    }
    if(ts>34 || sn>34 || ts<0 || sn<0)
        return 0;

    if(dp[i][ts][sn][done][a_bigger][b_smaller] != -1)return dp[i][ts][sn][done][a_bigger][b_smaller];

    int res=0;
    int  low,high;
    if(a_bigger)low=0;
    else low=a[i]-'0';
    if(b_smaller)high=9;
    else high=b[i]-'0';

    for(int  index=low;index<=high;index++){
        int  na=a_bigger,nb=b_smaller,ndone=done;
        if(index>low)na=1;
        if(index<high)nb=1;
        int  nts=ts,nsn=sn;
        if(index==3){
            nts++;
            ndone=1;
        }
        else if(index==6){
            nts--;
            nsn++;
            ndone=1;
        }
        else if(index==9) {
            nsn--;
            ndone=1;
        }

        res+=solve(i+1,nts,nsn,ndone,na,nb);
    }

    return dp[i][ts][sn][done][a_bigger][b_smaller]=res;
}

int  main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;
        while(a.size()<b.size())a.insert(0,"0");
        n=b.size();
        cout<<solve(0,17,17,0,0,0)<<endl;
    }
    return 0;
}