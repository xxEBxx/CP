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

const int maxn=101,maxm=10203;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,m,value[maxn],cost[maxn];
pair<int,int> dp[maxn][maxm][2];
//the values : first one is price spent and second is value aka flavour

ii solve(int i,int money,bool added){
    if(money < 0)return {1e9,-1e9};
    if(i==n) {
        if(added && m+200-money <= 2000)return {1e9,-1e9};

        return {0, 0};
    }//we didnt pay anything yet and we have no flavour yet

    if(dp[i][money][added]!=make_pair(-1,-1))return dp[i][money][added];
    //we need to maximize the value and minimize

    ii notake=solve(i+1,money,added),
    take1=solve(i+1,money-cost[i],added),
    take= make_pair(take1.f+cost[i],take1.s+value[i]);
    ii res;
    if(take.s > notake.s)res=take;
    else if(take.s < notake.s)res=notake;
    //better value
    else if(take.f > notake.f)res=notake;
    else res=take;
    //lower price
    return dp[i][money][added]=res;

}

int main(){fast();
    while(cin>>m>>n){
        for(int i=0;i<maxn;i++)for(int j=0;j<maxm;j++)  dp[i][j][0] = dp[i][j][1] = {-1, -1};
        for(int i=0;i<n;i++){
            cin>>cost[i]>>value[i];
        }
        ii res;
        if(m > 2000){
            res=solve(0,m+200,0);
        }
        else if(m > 1800){
            //cout<<solve(0,m+200,1).f<<endl;
            if(solve(0,m+200,1).f > 2000 && solve(0,m+200,1).s>=0)
                res=solve(0,m+200,1);
            else res=solve(0,m,0);
        }
        else res=solve(0,m,0);
        cout<<res.s<<endl;
    }
    return 0;
}