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

ll solve(vector<int> arr){
    ll curr=arr[0],max_val=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        curr+=arr[i];
        if(curr<0){
            curr=0;
        }
        if(curr>max_val){
            max_val=curr;
        }
    }
    return max_val;
}

int main(){fast();
    int n;
    while(cin>>n){
        if(n==0)break;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int res=solve(arr);
        if(res > 0)cout<<"The maximum winning streak is "<<res<<"."<<endl;
        else cout<<"Losing streak."<<endl;
    }
    return 0;
}