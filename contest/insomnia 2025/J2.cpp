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
        vector<int> arr(n),pref_gcd(n),suff_gcd(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        pref_gcd[0]=arr[0];
        suff_gcd[n-1]=arr[n-1];

        for(int i=1;i<n;i++){
            pref_gcd[i]=gcd(pref_gcd[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff_gcd[i]=gcd(suff_gcd[i+1],arr[i]);
        }
        int res=max(pref_gcd[n-2],suff_gcd[1]);
        for(int i=1;i<n-1;i++){
            res=max(res,gcd(pref_gcd[i-1],suff_gcd[i+1]));
        }
        cout<<res<<endl;
    }
    return 0;
}