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
    ll t;cin>>t;
    while(t--){
        ll n,k,x;cin >> n >> k >> x;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin >> arr[i];
        }

        ll total = 0;
        for(ll i=0;i<n;i++)
            total += arr[i];
        ll div = x/total;
        if(x % total == 0)div--;// one less added later in n

        
        ll curr = total*div,bad = div*n;
        if(k*total < x) {
            cout << 0 << endl;
        }
        else {
            for(ll i=n-1;i>=0;i--) {
                curr += arr[i];
                if(curr >= x)
                    break;
                bad++;
            }
            cout << n*k- bad<< endl;
        }
    }
    return 0;
}

