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

void generate_next_masks(int current_mask, int i, int next_mask, int n,vector<int>& next_masks){
    if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
    }
    if((current_mask & (1 << i)) != 0)
        generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
    if(i != n)
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0)
            generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);
    if((current_mask & (1 << i)) == 0)
        generate_next_masks
                (current_mask, i + 1, next_mask + (1 << i), n, next_masks);
}

int dp[1001][1<<11],n,m;
int solve(int col, int mask){
    if(col == m + 1){
        if(mask == 0)
            return 1;
        return 0;
    }
    if(dp[col][mask] != -1)
        return dp[col][mask];

    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);

    for(int next_mask: next_masks){
        answer = (answer + solve(col + 1, next_mask)) % mod;
    }

    return dp[col][mask] = answer;
}

int main() {fast();
    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0);

    return 0;
}