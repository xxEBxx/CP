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

int main() {
    fast();
    int n, m;
    while(cin >> n >> m) {
        vvi arr(n, vi(m)), dp(n, vi(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        if(n == 1) {
            int res = 0;
            for(int j = 0; j < m; j++) {
                res += arr[0][j];
            }
            bool first=true;
            for(int j = 0; j < m; j++) {
                if(!first)cout<<" ";
                cout << 1;
                first=false;
            }            cout << endl;
            cout << res << endl;
            continue;
        }

        // Initialize dp array with the last column of arr
        for(int i = 0; i < n; i++) dp[i][m-1] = arr[i][m-1];

        for(int j = m-2; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                dp[i][j] = arr[i][j] + dp[i][j+1]; // initialize with the right cell
                if(i == 0) dp[i][j] = min(min(dp[i][j],arr[i][j]+dp[n-1][j+1]), arr[i][j] + dp[i+1][j+1]); // upper diagonal
                else if(i == n-1) dp[i][j] = min(min(dp[i][j],arr[i][j]+dp[0][j+1]), arr[i][j] + dp[i-1][j+1]); // lower diagonal
                else dp[i][j]=min(min(dp[i][j],dp[i-1][j+1]+arr[i][j]),dp[i+1][j+1]+arr[i][j]);
            }
        }

        // Find the minimum path cost in the first column
        int res = dp[0][0], index_res = 0;
        for(int i = 1; i < n; i++) {
            if(dp[i][0] < res) {
                res = dp[i][0];
                index_res = i;
            }
        }

        // Trace back the path
        vi output(m);
        output[0]=index_res+1;
        for(int j=0;j<m-1;j++){
            int min_next=dp[index_res][j+1];

            if(index_res==0)min_next=min(min_next,dp[n-1][j+1]);
            else min_next=min(min_next,dp[index_res-1][j+1]);

            if(index_res==n-1)min_next=min(min_next,dp[0][j+1]);
            else min_next=min(min_next,dp[index_res+1][j+1]);
            //cout<<"for index"<<j<<" here is min_next"<<min_next<<endl;
            if(index_res==n-1) {
                if(min_next==dp[0][j+1])index_res = 0;
                else if(min_next==dp[n-2][j+1])index_res=n-2;
            }
            else if(index_res==0){
                if(min_next==dp[0][j+1])index_res=0;
                else if (min_next==dp[1][j+1])index_res=1;
                else index_res=n-1;
            }
            else {
                if(min_next==dp[index_res-1][j+1])index_res--;
                else if(min_next==dp[index_res][j+1]);
                else index_res++;
            }
            output[j+1]=index_res+1;
        }
        bool first=true;
        for(int j = 0; j < m; j++) {
            if(!first)cout<<" ";
            cout << output[j];
            first=false;
        }
        cout << endl;
        cout << res << endl;

    }
    return 0;
}
