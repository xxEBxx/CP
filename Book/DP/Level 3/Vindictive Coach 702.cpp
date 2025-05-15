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
const int maxn=25;

ll dp[maxn][2][maxn];
int n,m;

ll solve(int last_element,int bitmask , int dir){

    if(bitmask == (1<<n)-1)return 1ll;
    if(dp[last_element][dir][bitmask] != -1)return dp[last_element][dir][bitmask];

    ll res=0;

    if(dir==0){
        for(int i=0;i<last_element;i++) {
            if((bitmask & (1<<i)) == 0)//player not used yet
                res+=solve(i,bitmask | (1<<i) ,1-dir);
    }
    }

    else {
        for (int i = last_element + 1; i < n; i++) {
            if ((bitmask & (1 << i)) == 0)//player not used yet
                res += solve(i, bitmask | (1 << i), 1 - dir);
        }
    }
    return dp[last_element][dir][bitmask]=res;
}


int main(){fast();
    memset(dp,-1,sizeof(dp));
    while(cin>>n>>m){
        if(m==1){
            if(n==2 || n==1)cout<<1<<endl;
            else{
                ll res=solve(2,5,0);
                cout<<res<<endl;
            }
        }
        else{
            ll res=solve(m-1,(1<<(m-1)),0);
            cout<<res<<endl;
        }
    }
    return 0;
}