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

ll next(ll i){
    ll res=0;
    while(i>0){
        ll x=i%10;
        res += x*x;
        i = i/10;
    }
    return res;
}

int main(){fast();

    vi arr(406,0);
    for(ll i=1;i<406;i++){
        vi visited(406,0);
        ll current=i;
        ll res=i;
        while(visited[current] == 0){
            visited[current]=1;
            res=min(res,current);
            current=next(current);
        }
        arr[i]=res;
    }

    ll a,b;cin>>a>>b;
    ll res=0;
    for(ll i=a;i<=b;i++){
        if(i>405)
            res+=arr[next(i)];
        else
            res+=arr[i];
    }
    cout<<res;

    return 0;
}