#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)1e5+7;
const ll mod = 998244353;

int main(){fast();
    ll t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<k;i++){
            cout<<1;
}
        for(int i=0;i<n-k;i++){
            cout<<0;
        }
cout<<endl;
    }
    return 0;
}