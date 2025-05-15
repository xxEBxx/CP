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

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

map<ll,vector<pair<ll,ll>>> g,g1;

ll n,m,qu,lp[maxn],incident1[maxn],incident[maxn],lp1[maxn];

int main(){fast();
    memset(lp,0,sizeof(lp));
    memset(lp1,0,sizeof(lp1));
    memset(incident,0,sizeof(incident));
    memset(incident1,0,sizeof(incident));

    cin>>n>>m>>qu;
    for(ll i=0;i<m;i++){
        ll a,b,w;cin>>a>>b>>w;
        g[a].push_back(make_pair(b,w));
        g1[b].push_back(make_pair(a,w));
        incident[b]++;
        incident1[a]++;
    }
    //for(ll i=1;i<=n;i++)cout<<incident[i]<<" ";cout<<endl;
    queue<ll> q;
    for(ll i=2;i<=n;i++){
        if(incident[i]==0){
            for(auto child:g[i]){
                incident[child.f]--;
            }
        }
    }
    q.push(1);
    while(!q.empty()){
        ll parent=q.front();
        q.pop();
        for(auto child:g[parent]){
            lp[child.f]=max(lp[child.f] , child.s+lp[parent]);
            incident[child.f]--;
            if(incident[child.f]==0){
                q.push(child.f);
            }
        }
    }

    queue<ll> q1;
    q1.push(n);
    while(!q1.empty()){
        ll parent=q1.front();
        q1.pop();
        for(auto child:g1[parent]){
            lp1[child.f]=max(lp1[child.f] , child.s+lp1[parent]);
            incident1[child.f]--;
            if(incident1[child.f]==0){
                q1.push(child.f);
            }
        }
    }
    //for(ll i=1;i<=n;i++)cout<<lp[i]<<" ";cout<<endl;
    //for(ll i=1;i<=n;i++)cout<<lp1[i]<<" ";cout<<endl;
    lp[1]=0;
    lp1[n]=0;
    for(ll i=0;i<qu;i++){
        ll a;cin>>a;
        if(lp[a]==0 || lp1[a]==0)cout<<-1<<endl;
        else cout<<lp[a]+lp1[a]<<endl;
    }


    return 0;
}


