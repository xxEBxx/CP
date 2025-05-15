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
    int n;cin>>n;
    vector<int> arr(n);
    ll total=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }

    sort(all(arr));
    if(total-arr[n-1] >= arr[n-1] && total%2==0){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}