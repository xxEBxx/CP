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
int r,c;
int dp[(1<<17)];

int transform(int i,int j){
    i--;j--;
    return i*c+j;
}

bool check(int bitmask,int i){
    return bitmask & (1<<i);
}

int unset(int bitmask,int i){
    bitmask &= ~(1<<i);
    return bitmask;
}

int set_(int bitmask,int i){
    bitmask |= (1<<i);
    return bitmask;
}

int solve(int bitmask){
    if(__builtin_popcount(bitmask)==1)return 1;

    if(dp[bitmask]!=-1)return dp[bitmask];

    int res=0;
    for(int i=0;i<r*c;i++){
        if(((bitmask>>i)&1) == 1){
            //down
            if(i < ((r-2)*c) && check(bitmask,i+c) && !check(bitmask,i+2*c)){
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i+c);
                nb=set_(nb,i+2*c);
                res+=solve(nb);
            }
            //up
            if(i >= (2*c) && check(bitmask,i-c) && !check(bitmask,i-2*c)){
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i-c);
                nb=set_(nb,i-2*c);
                res+=solve(nb);
            }
            //right
            if((i%c) < c-2 && check(bitmask,i+1) && !check(bitmask,i+2)){
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i+1);
                nb=set_(nb,i+2);
                res+=solve(nb);
            }
            //left
            if((i%c) >= 2 && check(bitmask,i-1) && !check(bitmask,i-2)){
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i-1);
                nb=set_(nb,i-2);
                res+=solve(nb);
            }
            //top-left
            if((i%c) >= 2 && i >= (2*c) && check(bitmask,i-1-c) && !check(bitmask,i-2-2*c)) {
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i-1-c);
                nb=set_(nb,i-2-2*c);
                res+=solve(nb);
            }
            //top-right
            if((i%c) < c-2 && i >= (2*c) && check(bitmask,i+1-c) && !check(bitmask,i+2-2*c)) {
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i+1-c);
                nb=set_(nb,i+2-2*c);
                res+=solve(nb);
            }
            //bottop-right
            if((i%c) < c-2 && i < ((r-2)*c) && check(bitmask,i+1+c) && !check(bitmask,i+2+2*c)) {
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i+1+c);
                nb=set_(nb,i+2+2*c);
                res+=solve(nb);
            }
            //bottop-left
            if((i%c) >= 2 && i < ((r-2)*c) && check(bitmask,i-1+c) && !check(bitmask,i-2+2*c)) {
                int nb=bitmask;
                nb=unset(nb,i);
                nb=unset(nb,i-1+c);
                nb=set_(nb,i-2+2*c);
                res+=solve(nb);
            }
        }
    }
    return dp[bitmask]=res;
}

int main(){fast();
    int t;cin>>t;int tt=0;
    while(t--){
        tt++;
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>r>>c>>n;
        int bitmask=0;
        for(int ii=0;ii<n;ii++){
            int i,j;cin>>i>>j;
            bitmask|=(1<<transform(i,j));
        }
        //cout<<bitmask<<endl;
        cout<<"Case "<<tt<<": ";
        cout<<solve(bitmask)<<endl;
    }
    return 0;
}