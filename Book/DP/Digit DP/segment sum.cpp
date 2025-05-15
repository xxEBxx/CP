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
const int mod = 998244353;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    string a,b;cin>>a>>b;
    int k;cin>>k;
    while(a.size()<b.size())a='0'+a;
    int n=a.size();

    int dp[19][(1<<10)+1][2][2][2];
    int dp2[19][(1<<10)+1][2][2][2];

    //states are :index,bitmask,smaller,bigger,finished 0s at left(0 means we still have them aka didnt start yet the real number)

    for(int i=0;i<n;i++){
        for(int j=0;j< 1<<10;j++){
            for(int ab=0;ab<2;ab++){
                for(int bs=0;bs<2;bs++){
                    for(int l0=0;l0<2;l0++) {
                        dp[i][j][ab][bs][l0]=0;
                        dp2[i][j][ab][bs][l0]=0;
                    }}}}}
    dp[0][0][0][0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j< 1<<10;j++){
            for(int ab=0;ab<2;ab++){
                for(int bs=0;bs<2;bs++){
                    for(int l0=0;l0<2;l0++){
                        int high=b[i]-'0',low=a[i]-'0';
                        if(ab)low=0;
                        if(bs)high=9;

                        for(int index=low;index<=high;index++){
                            int na=ab,nb=bs,nbitmask=j|(1<<index),nl0=l0;
                            if(index>low) na = 1;
                            if(index<high)nb=1;
                            if(index>0)nl0=1;
                            if(l0==0 && index==0)nbitmask=0;//to remove absurdity

                            dp[i+1][nbitmask][na][nb][nl0]  += dp[i][j][ab][bs][l0];
                            dp2[i+1][nbitmask][na][nb][nl0] += dp2[i][j][ab][bs][l0] * 10 + index*dp[i][j][ab][bs][l0] ;
                            //dp2[i+1][nbitmask][na][nb][nl0] %= mod ;

                        }

                    }
                }
            }
        }
    }
    ll res=0;
    for(int bitmask=0;bitmask<1<<10;bitmask++){
        for(int j=0;j<2;j++){
            for(int l=0;l<2;l++){
                if(__builtin_popcount(bitmask)<=k){
                    res += dp2[n][bitmask][j][l][1];
                    //res %= mod;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}