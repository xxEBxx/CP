
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

ll atoi1(string s) {
    ll res =0;
    for (ll i =0;i<s.size();i++) {
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

bool comp(string a,string b) {
    string ida = "",idb=ida,na=ida,nb=ida;
    ll i=0;
    while (i<a.size() && a[i] != '-') {
        ida += a[i];i++;
    }
    i++;
    while (i<a.size()) {
        na += a[i];i++;
    }
    i=0;
    while (i<b.size() && b[i] != '-') {
        idb += b[i];i++;
    }
    i++;
    while (i<b.size()) {
        nb += b[i];i++;
    }

    if (na==nb) {
        return atoi1(ida) < atoi1(idb);
    }
    return na<nb;
}

int main() {
    fast();
    ll n;
    cin>>n;
    vector<string> arr(n);
    for (ll i =0;i<n;i++)
        cin>>arr[i];
    sort(all(arr),comp);
    for (auto elem : arr) {
        cout<<elem<<endl;
    }
    return 0;
}
