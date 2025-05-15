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
vi arr;int n;
ll dp[18][18];

ll solve(int index,int banned){
    if(index==n)return 1;
    if(arr[index]!=-1) {
        //cout<<"here is banned and arr and i "<<index<<" "<<banned<<" "<<arr[index]<<endl;
        if(abs(banned-arr[index]) <= 1 ) { //cout<<"skipped"<<endl;
            return 0; }
        return solve(index + 1, arr[index]);
    }
    //cout<<"here is dp "<<index<<banned<<dp[index][banned]<<endl;
    if(banned>=0 && dp[index][banned]!=-1)return dp[index][banned];
    ll res=0;
    for(int i=1;i<=n;i++){
        if(abs(banned-i) > 1){
            res+=solve(index+1,i);
        }
    }
    if(banned>=0)return dp[index][banned]=res;
    return res;
}
int main(){fast();
    string line;
    while(cin>>line){
        n=line.size();
        arr.clear();
        for(int i=0;i<line.size();i++){
            if(line[i]>='0' && line[i]<='9')arr.push_back(line[i]-'0');
            else if(line[i]=='?')arr.push_back(-1);
            else arr.push_back(10+line[i]-'A');
        }
        ll res=0;
        memset(dp,-1,sizeof(dp));
        //for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<dp[i][j]<<endl;
        if(arr[0]==-1){
                res+=solve(0,-500);
        }
        else res=solve(1,arr[0]);
        cout<<res<<endl;
    }
    return 0;
}