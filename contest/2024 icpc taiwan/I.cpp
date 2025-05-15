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

const int maxn=18;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,dp[(1<<maxn)+1][101],arr[maxn];
vector<int> current;

ll solve(int bitmask,int a_before){
    if(bitmask==((1<<(n-1))-1))
        return 1;

    if(dp[bitmask][a_before]!=-1)return dp[bitmask][a_before];

    for(int i=0;i<n-1;i++){
        if(((bitmask>>i)&1) == 0){
            if(arr[i] % a_before==0 && arr[i]/a_before<=100){
                current.push_back(arr[i]/a_before);
                if(solve(bitmask | (1 << i),arr[i]/a_before))return 1;
                else current.pop_back();
            }
        }
    }
    dp[bitmask][a_before] = 0;
    return 0;

}

int main(){fast();
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    //memset(dp,-1,sizeof(dp));
    //solve(0,5);
    for(int i = 1;i<=100;i++){
        memset(dp,-1,sizeof(dp));
        if(solve(0,i)){
            cout << "Yes" << endl;
            cout<< i <<" ";
            for(int j:current){
                cout << j << " ";
            }
            return 0;
        }
    }
    cout << "No";
    return 0;
}