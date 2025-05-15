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
const int maxn=302;
vi arr1,arr2;

int dp[maxn][maxn],t1,t2,n;
int solve(int i,int ncount){
    if(i==n) return 0;
    if(dp[i][ncount]!=-1)return dp[i][ncount];
    int bcount = i - ncount;
    int res1=1e9,res2=1e9;
    if(ncount < t1)res1 = arr1[i] + solve(i+1,ncount+1);
    if(bcount < t2)res2 = arr2[i] + solve(i+1,ncount);
    //we are sure they cant both be so great because if its the case we will break in the baginnig;
    return min(res1,res2);
}

int main(){fast();
    while(cin>>t1>>t2){
        if(t1==0 && t2==0)break;
        n=t1+t2;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=-1;
        arr1.clear();arr2.clear();
        int p;cin>>p;
        vi partitions(p);
        for(int i=0;i<p;i++){
            cin>>partitions[i];
            for(int j=0;j<partitions[i];j++){
                int val;cin>>val;
                arr1.push_back(val);
            }
            for(int j=0;j<partitions[i];j++){
                int val;cin>>val;
                arr2.push_back(val);
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
        int res=solve(0,0);
        cout<<res<<endl;
    }
    return 0;
}