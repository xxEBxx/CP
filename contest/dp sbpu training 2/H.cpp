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
int n,k,dp[maxn];
vi arr,diff(11);

int solve(int index){
    if(dp[index]!=-1)return dp[index];
    int res=0;
    for(int i=0;i<k;i++){
        //we try to find arr[index]+diff[i]
        int next=arr[index]+diff[i];
        bool exist=*lower_bound(arr.begin()+index-1,arr.end(),next) == next;
        cout<<"here is index i and exist"<<index<<" "<<i<<" "<<exist<<" "<<*lower_bound(arr.begin()+index,arr.end(),next)<<endl;
        if(exist){
            int next_index = lower_bound(arr.begin()+index,arr.end(),next)-arr.begin();
            res=max(res,1+solve(next_index));
        }
    }
    return dp[index]=res;
}


int main(){fast();
    cin>>n>>k;
    map<int,int> index;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        int v;cin>>v;arr.push_back(v);index[v]=i;}
    for(int i=0;i<k;i++) cin>>diff[i];
    vi lis(n);lis[n-1]=1;
    set<int> sorted;sorted.insert(arr[n-1]);
    int ans=1;
    for(int i=n-2;i>=0;i--){
        //i know elements needed by arr[i], ill search for them in sorted
        lis[i]=1;
        for(int j=0;j<k;j++){
            int next=arr[i]+diff[j];
            bool exist=*sorted.lower_bound(next)==next;
            //cout<<"here is i j next "<<i<<" "<<j<<" "<<next<<" "<<exist<<endl;
            if(exist) {
                lis[i] = max(lis[i], 1 + lis[index[next]]);
            }
        }
        sorted.insert(arr[i]);
        ans=max(ans,lis[i]);
    }
    //for(int elem:lis)cout<<elem<<" ";cout<<endl;
    cout<<ans;
    return 0;
}