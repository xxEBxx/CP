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

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> next_arr;
        next_arr.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i] != arr[i-1]){
                next_arr.push_back(arr[i]);
            }
        }
        arr=next_arr;
        n=(int)arr.size();

        int res=1;
        for(int i=1;i<n-1;i++){
            if(arr[i] < arr[i+1] && arr[i] < arr[i-1])
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}