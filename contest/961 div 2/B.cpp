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

const int maxn=2*(int)1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    int t;cin>>t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(all(arr));
        ll i=0,j=0,sum=0,res=0;
        if(m >= arr[i])sum=arr[i];
        arr.push_back(0);
        while(j<n){
            res=max(res,sum);
            if(i > j){
                j=i;
                sum=0;
                if(arr[j]<=m)sum=arr[j];
                continue;
            }
            if(sum+arr[j+1] <= m && arr[j+1]-arr[i]<=(ll)1){
                sum+=arr[j+1];
                j++;
            }
            else {
                sum-=arr[i];
                i++;
            }
        }
        cout<<res<<endl;

        }
    return 0;
}

/*

 */