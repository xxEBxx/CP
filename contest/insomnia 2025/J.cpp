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
        //sort(all(arr));
        //reverse(all(arr));
        int real_gcd=arr[0];
        for(int i=0;i<n;i++)
            real_gcd=gcd(arr[i],real_gcd);

        bool skipped=false;
        int gcd_far;
        if(real_gcd == arr[0]){
            skipped=true;
            gcd_far=arr[1];
        }
        else{
            gcd_far=arr[0];
        }
        for(int i=1;i<n;i++){
            if(!skipped && gcd(gcd_far,arr[i]) == real_gcd){
                skipped=true;
            }
            else{
                gcd_far=gcd(gcd_far,arr[i]);
            }
        }
        cout<<gcd_far<<endl;
    }
    return 0;
}