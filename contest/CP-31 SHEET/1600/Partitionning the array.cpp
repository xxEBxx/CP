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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
vvi divisors(maxn);

void estrathos(){
    for(int i=1;i<maxn;i++){
        for(int j=2*i;j<maxn;j+=i){
            divisors[j].push_back(i);
        }
    }
}

int main(){fast();
    estrathos();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int res=1;
        for(int div:divisors[n]){
            int gcd_far = -1;
            for(int i=0;i<n-div;i++){
                if(abs(arr[i]-arr[i+div]) != 0){
                    if(gcd_far==-1)gcd_far = abs(arr[i]-arr[i+div]);
                    else gcd_far=gcd(gcd_far,abs(arr[i]-arr[i+div]));
                }
            }
            if(gcd_far!=1)res++;
        }
        cout<<res<<endl;


    }
    return 0;
}