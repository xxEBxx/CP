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
int k,dp[10][90][90][2][2],n;

//states are: index far,remainder sum,remainder number,bigg first , small second
int solve(int i,int rm_sum,int rm_num,int a_bigger,int b_smaller){
    if(i==n)
        return (rm_sum==rm_num && rm_num==0);
    if(dp[i][rm_sum][rm_num][a_bigger][b_smaller]!=-1)return dp[i][rm_sum][rm_num][a_bigger][b_smaller];

    int res=0,high,low;
    if(a_bigger)low=0;
    else low=a[i]-'0';
    if(b_smaller)high=9;
    else high=b[i]-'0';

    for(int index=low;index<=high;index++){
        int nrm_sum=rm_sum+index,
            nrm_num=rm_num*10+index,
            na=a_bigger,
            nb=b_smaller;
        nrm_num%=k;
        nrm_sum%=k;
        if(index > low)na=1;
        if(index <high)nb=1;
        res+=solve(i+1,nrm_sum,nrm_num,na,nb);
    }
    return dp[i][rm_sum][rm_num][a_bigger][b_smaller]=res;
}

int main(){fast();
    int t,tt=0;cin>>t;
    while(t--){tt++;
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;
        n=b.size();
        while(a.size() < n)a.insert(0,"0");
        cin>>k;
        cout<<"Case "<<tt<<": ";
        if(k>=90)cout<<0<<endl;
        else cout<<solve(0,0,0,0,0)<<endl;
    }
    return 0;
}