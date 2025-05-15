//link : https://vjudge.net/problem/UVA-10664
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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=22;
const int mod=(int)1e9+7;

vi arr(maxn);
int n,total,dp[maxn][202];
//the goal is to achieve dp[n-1][x]=0
int solve(int i ,int curr){
    if (i==n) return abs(curr-(total-curr));
    if (dp[i][curr]!=-1) return dp[i][curr];
    return dp[i][curr]=
                   min(
                           solve(i+1,curr),
                           solve(i+1,curr+arr[i])
                   );
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        string line;
        total=0;
        getline(cin,line);
        while(line.empty())getline(cin,line);
        istringstream stream(line);
        int number;
        int i=0;
        while(stream>>number) {
            arr[i]=number;
            total+=arr[i];
            i++;
        }
        if(total&1){
            cout<<"NO"<<endl;continue;
        }
        n=i;
        //for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        memset(dp,-1,sizeof(dp));
        int res=solve(0,0);
        //cout<<res;
        if(res==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //we want arr[]
    return 0;
}
