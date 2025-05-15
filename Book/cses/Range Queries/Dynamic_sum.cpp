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

const int maxn=(int)1e5* 2 +7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int n,m;
vl b(maxn,0),arr(maxn,0);
ll gett(ll n){
    ll res=0;
    while(n>0){
        res+=b[n];
        n-= n & -n;
    }
    return res;
}

void sett(ll i ,ll v){
    ll diff = v - arr[i];
    arr[i]=v;
    while(i<=n){
        b[i] += diff;
        i += i & -i;
    }
}
void sett_init(ll i ,ll v){
    while(i<=n){
        b[i] += v;
        i+=i & -i;
    }
}

int main(){fast();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sett_init(i,arr[i]);
    }
    for(int i=0;i<m;i++){
        ll q,x,y;cin>>q>>x>>y;
        if(q==1){
            sett(x,y);
        }
        else{
            cout<<gett(y)-gett(x-1)<<endl;
        }
    }

    return 0;
}