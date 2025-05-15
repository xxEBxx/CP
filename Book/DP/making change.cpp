//link : https://vjudge.net/problem/UVA-166
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

vi min_coins(201,10000);
int prices[]={1,2,4,10,20,40};

int main(){fast();

    for(int elem:prices)min_coins[elem]=1;
    min_coins[0]=0;
    for(int i=1;i<201;i++){
        for(int j=0;j<6;j++){
            if(i >= prices[j]){
                min_coins[i] = min(min_coins[i],
                                   1 + min_coins[i - prices[j]]);
            }
        }
    }
    //cout<<min_coins[13]<<endl;
    int coins[6];
    while(true){
        for(int i=0;i<6;i++)cin>>coins[i];
        bool done=true;
        for(int i=0;i<6;i++) {
            if (coins[i] != 0){
                done=false;
                break;
            }
        }
        if(done)break;
        float num;cin>>num;
        num*=100/5;
        int n=(int)num;
        vvi dp(6,vi(401,1e9));
        for(int i=0;i<201;i++){
            dp[0][200-i] = min_coins[i];
        }

        for(int i=0;i <= coins[0];i++){
            dp[0][i+200]=i;
        }
        for(int i=0;i<=200;i++){
            for(int j=0;j<=coins[0];j++){
                dp[0][i+j]=min(dp[0][i+j],
                             dp[0][i]+j);
            }
        }
        //do all the minusus manually;
        for(int i=1;i<6;i++){
            for(int mon=0;mon<401;mon++){
                //dp[i][mon]=min(dp[i][mon],dp[i-1][mon]);

                for(int occ=0;occ <= coins[i] ; occ++){
                    int add=mon+(prices[i]*occ);
                    if(add < 401){
                        dp[i][add] = min(dp[i][add],dp[i-1][mon]+occ);
                        //cout<<"here is dp i add val "<<i<<" "<<add<<" "<<dp[i][add]<<endl;
                    }
                }
            }
        }

        int res=dp[5][200+n];
        if(res<10)cout<<"  "<<res<<endl;
        else if (res<100)cout<<" "<<res<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
/*
 int minus=mon-coins[i],occ=1;
                while(minus >= 0){
                    dp[i][minus] = min(dp[i][minus],
                                       dp[i][mon] + occ);
                    minus -= coins[i];
                    occ++;
                }
 */
