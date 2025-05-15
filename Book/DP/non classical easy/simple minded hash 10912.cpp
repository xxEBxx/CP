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

vector<vector<vector<int>>> dp(352,vvi(28,vi(28,-1)));
int l,s;
int solve(int sum,int elements,int low){
    if(elements==0 && sum==0)return 1;//jbna zok
    if(sum <= 0 || elements<=0) return 0;
    if(dp[sum][elements][low]!=-1)return dp[sum][elements][low];
    int res=0;
    for(int i=low+1;i<27;i++){
        res+=solve(sum-i,elements-1,i);
    }
    return dp[sum][elements][low]=
            res;
}

int main(){fast();
    int tt=0;
    while(cin>>l>>s){
        if(l==0 && s==0)break;
        tt++;
        for(int i=0;i<326;i++)for(int j=0;j<28;j++)for(int k=0;k<28;k++)dp[i][j][k]=-1;
        cout<<"Case "<<tt<<": ";

        if(l>26 || s>=352 ){
            cout<<0<<endl;
            continue;}
        cout<<solve(s,l,0)<<endl;
    }
    return 0;
}