#include <bits/stdc++.h>

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

const int maxn = (int)1e6+7;
const int mod = (int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n;
int arr[366], dp[366][2];

int solve(int i, int cad){
    if(i == n){
        return cad == 0 ? 0 : 100000;
    }

    if(dp[i][cad] != -1) return dp[i][cad];

    int res = solve(i + 1, cad);
    int take = 0;

    if (cad) {
        if (arr[i] != 0) // check for division by zero
            take = solve(i + 1, 1 - cad) * (0.97 / (double)arr[i]);
    } else {
            take = solve(i + 1, 1 - cad) * (0.97 * (double)arr[i]);
    }

    res = max(res, take);
    //cout<<res<<endl;
    return dp[i][cad] = res;
}

int main() {
    fast();
    while(cin >> n) {
        if(n == 0) break;

        for(int i=0;i<366;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        for(int i = 0; i < n; i++) {
            double v;cin>>v;
            arr[i]=(int)(v*100);
        }

        int res = solve(0, 1);
        cout <<fixed<<setprecision(2)<< floor(((double)res/100)*100)/100 << endl;
    }

    return 0;
}
