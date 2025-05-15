#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
        int n;cin>>n;
        string s=" ",s1;cin>>s1;
        s+=s1;
        vector<int> arr(n+1,0);
        for(int i=1;i<n+1;i++){
            cin>>arr[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll>(4,0));
//second state is cost to remove all h/ha/har/hard
        dp[0][0]=0;
        dp[0][1]=dp[0][2]=dp[0][3]=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='h'){
                dp[i][0]=dp[i-1][0]+arr[i];
                dp[i][1]=min(dp[i-1][1],dp[i-1][0]);
//if we are at h and i,1 then we are banning ha so we can accept not removing the h
                dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3];
            }
            else if(s[i]=='a'){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1]+arr[i];
                dp[i][2]=min(dp[i-1][2],dp[i-1][1]);
                dp[i][3]=dp[i-1][3];
            }
            else if(s[i]=='r'){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2]+arr[i];
                dp[i][3]=min(dp[i-1][3],dp[i-1][2]);
            }
            else if(s[i]=='d'){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3]+arr[i];
            }
            else {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3];
            }
        }
        ll res=min(dp[n][0],dp[n][1]);
        res=min(res,min(dp[n][2],dp[n][3]));
        cout<<res<<endl;

    return 0;
}