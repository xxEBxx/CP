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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=102;

int n,m,k,t[maxn],e[maxn],val[maxn],dp[maxn][maxn][maxn];

int solve(int index,int time,int energy){
    if(time > m || energy > k)return -1e9;
    if(index==n)return 0;
    if(dp[index][time][energy]!=-1)return dp[index][time][energy];
    return dp[index][time][energy]=
    max(solve(index+1,time,energy),//not taking
            val[index]+solve(index+1,time+t[index],energy+e[index])
            );
}

int main(){fast();
    cin>>n>>k>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>val[i]>>e[i]>>t[i];


    for(int energy=0;energy <= k;energy++){
        for(int time=0;time<=m;time++){
            if(t[0] <= time && e[0] <= energy)dp[0][energy][time]=val[0];
            else dp[0][energy][time]=0;
        }
    }

    for(int i=1;i<n;i++){
        for(int energy=0;energy <= k;energy++){
            for(int time=0;time<=m;time++){
                dp[i][energy][time]=dp[i-1][energy][time];
                if(time >= t[i] && energy >= e[i])
                    dp[i][energy][time]=max(dp[i][energy][time],
                                            val[i]+dp[i-1][energy-e[i]][time-t[i]]);
            }
        }
    }
    int res=dp[n-1][k][m];
    cout<<res<<endl;
    int index=n-1,time_far=m,energy_far=k,score=0;
    vi ans;
    while(index > 0){
        if(energy_far>=e[index] && time_far>=t[index] && dp[index][energy_far][time_far]
           ==
           val[index]+dp[index-1][energy_far-e[index]][time_far-t[index]]){
            //this means we took the index'th element
            ans.push_back(index);
            time_far-=t[index];
            energy_far-=e[index];
            score+=val[index];
        }
        index--;
    }
    sort(all(ans));
    if(score < res)cout<<1<<" ";
    for(int kk : ans)cout<<kk+1<<" ";cout<<endl;
    return 0;
}
/*


    */