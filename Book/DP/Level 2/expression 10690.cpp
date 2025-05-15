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

int n,m,arr[101],total,offset=2500;
ii dp[103][52][5005];  // using pairs for dp

ii solve(int i, int taken, int sum){
    if (i == n + m) {
        int val = (total + offset - sum) * (sum - offset);
        return {val, val};  // Both max and min are the same at the base case
    }

    if(dp[i][taken][sum].f != -1) return dp[i][taken][sum];

    ii res = {-1e9, 1e9};  // Initialize max as very small and min as very large

    if(taken < n){
        // Going to set 1
        ii loc = solve(i+1, taken+1, sum+arr[i]);
        res.f = max(res.f, loc.f);  // max result
        res.s = min(res.s, loc.s);  // min result
    }
    if(i-taken < m){
        // Going to set 2
        ii loc = solve(i+1, taken, sum);
        res.f = max(res.f, loc.f);  // max result
        res.s = min(res.s, loc.s);  // min result
    }

    return dp[i][taken][sum] = res;
}

int main(){fast();
    while(cin >> n >> m){
        total = 0;
        int total_abs = 0;
        for(int i = 0; i < n + m; i++){
            cin >> arr[i];
            total += arr[i];
            total_abs += abs(arr[i]);
        }

        // Initialize dp with invalid values
        for(int i = 0; i <= n + m; i++)
            for(int j = offset - total_abs; j <= offset + total_abs; j++)
                for(int k = 0; k <= max(n,m); k++)
                    dp[i][k][j] = {-1, -1};

        ii res = solve(0, 0, offset);  // Call the merged solve function
        cout << res.f << " " << res.s << endl;  // Output max and min results
    }
    return 0;
}
