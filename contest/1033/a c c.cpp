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
    ll x,d;
    cin>>x>>d;
    ll curr_d=1;
    vi ans;
    while (x>0){
        ll i =1,p=2;
        while (p-1 <= x) {
            i++;
            p*=2;
        }
        i--;
        p/=2;
        x -= p-1;
        for (ll ii=0;ii<i;ii++)
            ans.push_back(curr_d);
        curr_d += d+1;
    }
    if (ans.size() > 1e4) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for (auto elem : ans) {
        cout<<elem<<" ";
    }
    return 0;
}
