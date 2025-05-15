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

vector<int> dp(1e5+7,-1);
int l ,r;
int solve(vector<int> arr,int i,int curr){
    int n=arr.size();
    if (i==n)return curr;
    if(dp[i]!=-1)return dp[i];

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n>>l>>r;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    return 0;
}