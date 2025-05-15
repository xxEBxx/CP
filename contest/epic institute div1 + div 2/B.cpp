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

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> arr(n),needed(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll max_so_far=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]  >= max_so_far){
                max_so_far=arr[i];
                continue;
            }
            needed[i]=max_so_far - arr[i];
        }
        //for(int elem:needed)cout<<elem<<" ";
        sort(all(needed));
        //for(int elem:needed)cout<<elem<<" ";
        ll index=0,added=0,res=0;
        while(index < n){
            if(needed[index]==added) { index++;continue; }
            res+=(n-index+1)*(needed[index]-added);
            added = needed[index];
            index++;
        }
        cout<<res<<endl;
    }
    return 0;
}