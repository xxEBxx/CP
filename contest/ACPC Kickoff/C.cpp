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

const ll maxn=(ll)1e3+2;
const ll mod=(ll)1e9+7;

ll facto[maxn],inv_facto[maxn];

ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

ll c(ll i,ll n){
    ll res = facto[n];
    res *= inv_facto[i];
    res%=mod;
    res *= inv_facto[n-i];
    res%=mod;
    return res;
}


int main(){fast();
    facto[0] =1;
    for(ll i=1;i<maxn;i++){
        facto[i]=i*facto[i-1];
        facto[i] %=mod;
    }
    inv_facto[maxn-1]=inv(facto[maxn-1]);
    for(ll i=maxn-2;i>=0;i--){
        inv_facto[i] = (i+1) * inv_facto[i+1];
        inv_facto[i] %= mod;
    }

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> arr(n),done(n+1,0),segment;
        ll z=0,all_z=0,index=-1;
        int res=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]!=0 && done[arr[i]] == 1){
                res=-1;
            }
            done[arr[i]]=1;
            if(arr[i]==0 ) {
                all_z++;
                if(segment.empty())z++;
            }
            else {
                if(segment.empty() || arr[i-1]==segment[segment.size()-1])
                    segment.push_back(arr[i]);
                else
                    res=-1;
            }
        }

        bool valid = true;
        for(int i =0;i<segment.size();i++){
            if(abs(segment[i+1]-segment[i]) !=1 )
                valid=false;
        }

        if(res==-1 || !valid) {
            cout << 0 << endl;
            continue;
        }

        cout<<c(z,z)<<endl;

    }
    return 0;
}