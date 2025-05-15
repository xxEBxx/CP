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
int n,m,dp[10][10],visited[11];

int solve(int i,int count){
    if(count==n)return 1;
    if(dp[i][count]!=-1)return dp[i][count];

    int res=0;
    for(int index=max(1,i-2);index<=min(10,i+2);index++){
        if(visited[index]==0)continue;
        //cout<<i<<" "<<index<<endl;
        res+=solve(index,count+1);
    }
    return dp[i][count]=res;
}

int main(){fast();
    int t,tt=0;cin>>t;
    while(t--){tt++;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<11;i++)visited[i]=0;
        cin>>m>>n;
        for(int i=0;i<m;i++){
            int v;cin>>v;
            visited[v]=1;
        }
        int res=0;
        for(int i=1;i<11;i++){
            //cout<<visited[i]<<" ";
            if(visited[i]==1){
                res+=solve(i,1);
            }
        }
        cout<<"Case "<<tt<<": "<<res<<endl;
    }
    return 0;
}