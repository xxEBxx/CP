
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


ll solve(vi arr) {
    ll n=arr.size();
   if (n==0)return n;
    ll res=0;
    //we fix the middle
    ll index = arr[n/2]-1;
    for (ll i=n/2-1;i>=0;i--) {
        res += index - arr[i];
        index--;
    }
    index = arr[n/2]+1;
    for (ll i=n/2+1;i<n;i++) {
        res += arr[i]-index;
        index++;
    }
    return res;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin>>s;
        vi  a,b;
        for (ll i=0;i<n;i++) {
            if (s[i]=='a')
                a.push_back(i);
            else
                b.push_back(i);
        }
        cout<<min(solve(a),solve(b))<<endl;
    }
    return 0;
}
