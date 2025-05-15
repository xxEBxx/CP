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

const int maxn=1002;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,m,price1[maxn],price2[maxn];
pair<int,int> dp[maxn][maxn];
string name1[maxn],name2[maxn];

ii solve(int i,int j){
    if(i==n || j==m)return {0,0};

    if(dp[i][j].f !=-1)return dp[i][j];

    int max_price=0,bridges=1e9;

    for(int next_i=i ; next_i<n ; next_i++){
        if(name1[next_i] == name2[j]){
            //make a bridge
            ii loc = solve(next_i+1, j+1);
            // we made a bridge between next i and j
            if( max_price < loc.f + price1[next_i] + price2[j]){
                max_price=loc.f + price1[next_i] + price2[j];
                bridges=1+loc.s;
            }
            if( max_price == loc.f + price1[next_i] + price2[j]){
                bridges=min(bridges,1+loc.s);
            }
        }
    }

    for(int next_j=j;next_j<m;next_j++){
        if(name1[i]==name2[next_j]){
            ii loc=solve(i+1,next_j+1);
            if( max_price < loc.f + price1[i] + price2[next_j]){
                max_price=loc.f + price1[i] + price2[next_j];
                bridges= 1 +loc.s;
            }
            else if( max_price == loc.f + price1[i] + price2[next_j]){
                bridges=min(bridges,1 + loc.s);
            }

        }
    }
    return dp[i][j]={max_price,bridges};

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            string trash;cin>>trash;
            cin>>name1[i];
            cin>>price1[i];
        }
        cin>>m;
        for(int i=0;i<m;i++){
            string trash;cin>>trash;
            cin>>name2[i];
            cin>>price2[i];
        }
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]={-1,-1};
        ii res=solve(0,0);
        cout<<res.f<<" "<<res.s<<endl;


    }

    return 0;
}