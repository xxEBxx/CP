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
        ll n,a,b;cin>>n>>a>>b;
        if(a>=b){
            cout<<a*n<<endl;
            continue;
        }
        if(n < (b-a)){
            cout<<b*(b+1)/2-(b-n)*(b-n+1)/2<<endl;
            continue;
        }
        ll res=a*(n-(b-a))+b*(b+1)/2-a*(a+1)/2;
        //cout<<"to sell for a"<<a*(n-(b-a))<<endl;
        //cout<<"to sell from a to b"<<b*(b+1)/2-a*(a+1)/2<<endl;
        cout<<res<<endl;
    }
    return 0;
}