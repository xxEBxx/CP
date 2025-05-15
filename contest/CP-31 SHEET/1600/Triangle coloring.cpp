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

ll facto[maxn];

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}


int main(){fast();
    facto[0]=1;
    for(ll i=1;i<maxn;i++){
        facto[i]=facto[i-1]*i;
        facto[i]%=mod;
    }

    ll n;cin>>n;
    vi arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];

    ll res=1;
    for(ll i=0;i<n/3;i++){
        vi loc={arr[3*i],arr[3*i+1],arr[3*i+2]};
        sort(all(loc));
        ll coeff = 1;
        if(loc[0]==loc[2])
            coeff=3;
        else if(loc[0]==loc[1])
            coeff=2;

        res*=coeff;
        res%=mod;
    }

    ll mult = facto[n/3];
    mult *= inv(facto[n/6]);
    mult%=mod;
    mult *= inv(facto[n/6]);
    mult%=mod;
    //cout<<res<<" "<<mult<<endl;
    cout<<(mult*res)%mod<<endl;
    return 0;
}