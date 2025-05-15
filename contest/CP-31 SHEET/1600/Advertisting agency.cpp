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

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)1e3+2;
int dp[maxn][maxn];
int c(int n,int k){
    if(n==k)
        return 1;
    if(k==1)
        return n;
    if(dp[n][k]!=-1)
        return dp[n][k];
    int res=c(n-1,k-1);
    res += c(n-1,k);
    res%=mod;
    return dp[n][k]=res;
}


int main(){fast();
    int t;cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(all(arr));
        reverse(all(arr));
//we will try all combinations of the k'th element
        int elem=arr[k-1],before=0,total=0;
        for(int i=0;i<n;i++){
            if(arr[i]==elem){
                if(i<k)before++;
                total++;
            }
        }

        cout<<c(total,before)<<endl;

    }
    return 0;
}