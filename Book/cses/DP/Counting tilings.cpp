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
int n,m;
//try to use for each column a bitmask of elements li 3amrin
int dp[1001][(1<<10)+1];

int solve(int i,int bitmask){
    if(i==n)
        return 1;
    if(dp[i][bitmask]!=-1)
        return dp[i][bitmask];
    int n_bitmask=0,res=0;
    vi poss;
    all.clear();
    for(int j=0;j<n-1;j++){
        if((bitmask>>j)==1)continue;

        if((bitmask>>(j)))
    }
}
vi all;
void generate_bitmasks(int bitmask,int i){
//this function should find all possible next bitmasks
    if(i==n)
        return;
    if((bitmask>>i)&1) {
        generate_bitmasks(bitmask, i + 1);
        return;
    }
    if(((bitmask>>(i+1))&1) == 1){
        for(int index=0;index<all.size();index++){
            all[index] |= (1<<index);
        }
        generate(bitmasksl)
    }


}

int main(){fast();
    cin>>n>>m;
    return 0;
}