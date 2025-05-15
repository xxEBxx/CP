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

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

string s;
int n;
int dp[52][52],ps[52];

int solve(int i,int j){
    if( i+1 == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int res=1;
    for(int i1 = i ; i1 <= j;i1++){
        for(int j1 = i ; j1 <= j ; j1++){
            if( ps[i1]-ps[i-1] == ps[j]-ps[j1-1] ){
                res += solve(i1+1,j1-1) ;
                res%=mod;
            }
        }
    }
    return dp[i][j] = res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>s;
        n=s.size();

        for(int i=1;i<=s.size();i++){
            ps[i] = ps[i-1]+s[i-1]-'0';
        }
        cout<<solve(1,n)<<endl;
    }
    return 0;
}
//between i and j how much way can i find 1 ,2 ,3
//we have i j , we try finding 2 equal numbers and give to next
//what is different is we won't come to same place i guess