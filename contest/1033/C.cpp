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

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;

        if (m<n || m > (n+1)*n/2 ) {
            cout<<-1<<endl;
            continue;
        }
        vi used(n+1,0);
        vi order;
        ll curr = n;
        while (curr > 0) {
            if (m-curr >= curr ) {
                order.push_back(curr);
                m -= curr;
                used[curr]=1;
                curr--;
            }
            else if (used[m-curr+1]==0){
                order.push_back(m-curr+1);
                used[m-curr+1]=1;
                for (ll i=1;i<=n;i++) {
                    if (used[i]==0)
                        order.push_back(i);
                }
                break;
            }
            else {
                order.push_back(curr);
                m -= curr;
                used[curr]=1;
                curr--;
            }
        }
        cout<<order[0]<<endl;
        for (ll i=0;i<n-1;i++) {
            cout<<order[i]<<" "<<order[i+1]<<endl;
        }
    }
    return 0;
}
