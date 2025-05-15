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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

vi arr;
unordered_map<int,int> counter;
int dp[10001][101];
int n,k,s;

int solve(int i,int j){
    //i index , j number of students int this TD
    if(j > s)
        return 0;
    if(i >= arr.size())
        return 1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int res = solve(i+1,counter[arr[i]]);
    int so_far=counter[arr[i]],index=i+1;
    while(index < arr.size() && arr[index]-arr[i] <= k && so_far<=s){
        so_far += counter[arr[index]];
        res += solve(index+1,so_far);
        index++;
        res %= mod;
    }

    return dp[i][j]=res;
}

int main(){fast();
    memset(dp,-1,sizeof(dp));
    cin>>n>>k>>s;
    arr.assign(n,0);
    set<int> unique;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        unique.insert(arr[i]);
        counter[arr[i]]++;
    }
    arr.clear();
    for(auto elem : unique)
        arr.push_back(elem);

    cout<<solve(0,0)<<endl;
    return 0;
}