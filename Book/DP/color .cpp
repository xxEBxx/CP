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
string a;
int n,dp[maxn][maxn];
// our states are the current index and the place we are already red on
vector<string> subs;

int q;

int solve(int index,int red_until){
//red until means red_until is still black
    if(red_until==n)
        return 0;
    if(dp[index][red_until]!=-1)
        return dp[index][red_until];
    int res=1e9;
    for(int i=0;i<q;i++){
        if(index + subs[i].size() >= n){

        }
        bool take=true;
        for(int j=0;j<)
    }

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }cin>>q;
        for(int i=0;i<q;i++){
            string val;cin>>val;
           subs.push_back(val);
        }
        subs.clear();
    }
    return 0;
}