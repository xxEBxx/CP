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

int main(){fast();
    int n,m;cin>>n>>m;
    string a;cin>>a;
    a='a'+a;
    vvi dp(6,vi(n+1,0));
    vector<string> bases(6,"#");
    for(int i=1;i<1e5;i++){
        bases[0]+="abc";
        bases[1]+="acb";

        bases[2]+="bac";
        bases[3]+="bca";

        bases[4]+="cab";
        bases[5]+="cba";
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++){
            if(a[i] == bases[j][i]){
                dp[j][i]++;
            }
        }
    }
    //we make the dp a prefix sum of these
    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++)
            dp[j][i] += dp[j][i-1];
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int res=0;//number of right elements
        for(int j=0;j<6;j++){
            res = max(res, dp[j][y] - dp[j][x-1]);
        }
        cout<<y-x+1 - res<<endl;
    }
    return 0;
}