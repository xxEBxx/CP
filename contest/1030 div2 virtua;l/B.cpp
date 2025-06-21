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

const ll maxn=(ll)1e5+7;
const ll mod = 998244353;

int main(){fast();
    ll t;cin>>t;
    while(t--) {
        int n;cin>>n;
        cout<<2*(n-1)<<endl;
        for (int i=0;i<n-1;i++) {
            int to_switch = (i/2)+1+(n%2==0);
            if (i&1){
                cout << i + 2 << " " << 1 << " " << 1 + to_switch << endl;
                cout << i + 2 << " " << n - to_switch << " " << n << endl;
            }
            else {
                cout << i + 2 << " " << n - to_switch << " " << n << endl;
                cout << i + 2 << " " << 1 << " " << 1 + to_switch << endl;

            }
        }
    }
    return 0;
}