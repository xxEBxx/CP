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

const ll maxn=(ll)3*1e5+7;
const ll mod=(ll)998244353;

int main(){fast();
    ll t;cin>>t;

    ll pow[maxn];
    pow[0]=1;
    for(ll i=1;i<maxn;i++){
        pow[i] = 2* pow[i-1];
        pow[i] %= mod;
    }
    while(t--){
        ll n,m;cin>>n>>m;
        vector<ll> arr(n);
        vvi g(n+1);
        for(ll i=0;i<m;i++){
            ll a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vi color(n+1,-1),g1,g2;
        bool exist=true;
        for(ll i=1;i<=n;i++){
            if(color[i] > -1)continue;
            queue<ll> q;
            q.push(i);
            color[i]=0;
            ll count_1=0,count_2=0;
            while(!q.empty()){
                ll head = q.front();
                q.pop();
                if(color[head]==0)count_1++;
                else count_2++;

                for(auto c : g[head]){
                    if(color[head] == color[c]) { exist = false; break;}
                    if(color[c] > -1)continue;
                    color[c] = 1- color[head];
                    q.push(c);
                }

            }
            g1.push_back(count_1);
            g2.push_back(count_2);
            if(!exist)break;
        }


        if(!exist){
            cout<<0<<endl;
            continue;
        }

        ll res=1;
        for(ll i=0;i<g1.size();i++){
            //in g1 give them 1 or 3 so 2 multiplied by g1 ,
            ll loc =pow[g1[i]] ;
            loc %= mod;
            loc += pow[g2[i]] ;
            loc %= mod;
            res*=loc;
            res %= mod;

        }
        cout<<res<<endl;

    }
    return 0;
}

