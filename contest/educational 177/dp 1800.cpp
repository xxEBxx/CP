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

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;


int main(){fast();
    vector<ll> a(3),b(3);
    for(ll & i : a)
        cin>>i;
    for(ll & i : b)
        cin>>i;

    //00,11,22  01,10,22  02,20,11
    //00,12,21  01,12,21  02,12,21
    ll res = a[0]/b[0] * (a[1]/b[1]) * (a[2]/b[2]);
    res=max(res,a[0]/b[0] * (a[1]/b[2]) * (a[2]/b[1]));
    res=max(res,a[0]/b[1] * (a[1]/b[0]) * (a[2]/b[2]));
    res=max(res,a[0]/b[1] * (a[1]/b[2])*(a[2]/b[0]));
    res=max(res,a[0]/b[2] * (a[1]/b[0]) * (a[2]/b[1]));
    res=max(res,a[0]/b[2] *(a[1]/b[1]) * (a[2]/b[0]));

    cout<<res<<endl;

    return 0;
}