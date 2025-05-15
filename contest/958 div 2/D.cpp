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

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
ll n;
const ll maxn=3*100007;
vi visited(maxn,0);
ll sum1,sum2;
vector<ll> force(maxn);
map<ll,vector<ll>> g;

void solve(ll i,int number){
    visited[i]=1;
    if(number) sum1+=force[i];
    else sum2+=force[i];

    for(auto elem : g[i]){
        if(visited[elem]==0)
            solve(elem,1-number);
    }

}

int main(){fast();
    int t;cin>>t;
    while(t--){
        g.clear();
        sum1=sum2=0;
        cin>>n;
        for(int i=1;i<=n;i++)visited[i]=0;
        for(int i=1;i<=n;i++){
            cin>>force[i];
        }
        for(int i=1;i<=n-1;i++){
            ll a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        solve((ll)1,0);
        //cout<<sum1<<" "<<sum2<<endl;
        ll res = sum1+sum2;
        if(sum1 > sum2)res+=sum2;
        else res+=sum1;
        cout<<res<<endl;
    }
    return 0;
}