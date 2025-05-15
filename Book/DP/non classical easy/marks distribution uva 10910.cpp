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

const int maxn=(int)72;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int dp[maxn][maxn];
    for(int i=0;i<maxn;i++){
        dp[1][i]=1;
        dp[i][0]=1;
    }
    //states are number of subjects and free money
    for(int subject=2;subject<maxn;subject++){
        for(int marks=1;marks<maxn;marks++){
            dp[subject][marks]=0;
            for(int submarks=0;submarks<=marks;submarks++){
                dp[subject][marks]+=dp[subject-1][submarks];
            }
        }
    }

    int t;cin>>t;
    while(t--){
        int n,all,topass;cin>>n>>all>>topass;
        cout<<dp[n][all-n*topass]<<endl;
    }
    return 0;
}