#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
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
        int n,f,k;cin>>n>>f>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int fav_number=arr[f-1];
        sort(all(arr));
        reverse(all(arr));
        if(n==k)cout<<"Yes"<<endl;
        else if(fav_number == arr[k] && arr[k]==arr[k-1]){
            cout<<"Maybe"<<endl;
        }
        else if(fav_number > arr[k]){
            cout<<"Yes"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}