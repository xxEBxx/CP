#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

ll solve(ll a,ll b,char op){
       if(op=='+')
            return a+b;
        if(op=='-')
            return a-b;
    if(op=='*')
        return a*b;
    if(op=='/')
        return a/b;
}
int main() {
    fast();
    ll a,b,c;
    char d,e;
    cin>>a>>d>>b>>e>>c;

    if((e=='*' || e=='/') && (d=='+' || d=='-')){
        ll ller = solve(b,c,e);

        ll res=solve(a,ller,d);
        cout<<res<<endl;
return 0;
}
    ll ller = solve(a,b,d);
    ll res =solve(ller,c,e);
       cout<<res<<endl;
    return 0;
}
