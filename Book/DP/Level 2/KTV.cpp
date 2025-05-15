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

const int maxn=81;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,dp[maxn][(1<<9)+1];
int arr1[maxn],arr2[maxn],arr3[maxn],value[maxn];

int solve(int i, int bitmask){
    if(i==n){
        if(bitmask != ((1<<9)-1))return -1e9;
        return 0;
    }
    if(dp[i][bitmask]!=-1)return dp[i][bitmask];

    int res=solve(i+1,bitmask);
    if((bitmask & (1<<arr1[i]))==0 && (bitmask & (1<<arr2[i]))==0 && (bitmask & (1<<arr3[i]))==0){
        res=max(res,solve(i+1,bitmask | (1<<arr1[i])| (1<<arr2[i])| (1<<arr3[i]) )+value[i]);
    }

    return dp[i][bitmask]=res;
}

int main(){fast();
    int tt=0;
    while(cin>>n){tt++;
        memset(dp,-1,sizeof(dp));
        if(n==0)break;
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
            arr1[i]--;
            cin >> arr2[i];
            arr2[i]--;
            cin >> arr3[i];
            arr3[i]--;
            cin >> value[i];
        }
        int res = solve(0, 0);
        cout<<"Case "<<tt<<": ";
        if (res < 0)cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}