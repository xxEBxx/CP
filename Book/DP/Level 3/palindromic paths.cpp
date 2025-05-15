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

const int maxn=51;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n;
char arr[maxn][maxn];

string dp[maxn][maxn];

string solve(int i,int j){
    if(i==j) return "";
    if(i==j-1) {
        string res="";
        res+=arr[i][j];
        return res;
    }
    if(dp[i][j]!="")return dp[i][j];

    //dont forget we need the longest child , if theres none we just directly jump from i to j
    string res="";
    res+=arr[i][j];
    for(int k=i+1;k<j;k++){
        for(int l=k; l < j ;l++){
            if(arr[i][k]==arr[l][j]){
                string curr="";

                curr+=arr[i][k];
                curr+=solve(k,l);
                curr+=arr[l][j];

                if(curr.size() > res.size()){
                    res=curr;
                }
                else if(curr.size() == res.size() && curr<res){
                    res=curr;
                }
            }
        }
    }
    return dp[i][j]=res;
}

int main(){fast();
    int t;cin>>t;
    while(t--){cin>>n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin >> arr[i][j];
        }
        cout<<solve(0,n-1)<<endl;
    }
    return 0;
}