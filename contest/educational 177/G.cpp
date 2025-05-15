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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

bool work(vi arr,int x,int k){
    //we keep going until the mex is equal to x or more
    int n=arr.size();
    unordered_map<int,int> m;
    int counter = x;//number of elements smaller than k
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=x)continue;

        m[arr[i]]++;
        if(m[arr[i]] == 1)
            counter--;
        if(counter==0){
            counter = x;
            m.clear();
            res++;
        }
    }
    return res >= k;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int a=0,b=2*1e5,mid;
        while(a < b-1){
            mid=(a+b)/2;
            if(work(arr,mid,k)){
                a=mid;
            }
            else{
                b=mid-1;
            }
        }
        if(work(arr,b,k))cout<<b<<endl;
        else cout<<a<<endl;
    }
    return 0;
}