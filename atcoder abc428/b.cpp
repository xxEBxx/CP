
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int main() {
    fast();
    int n,m;
    cin>>n>>m;
    string s;cin>>s;
    unordered_map<string,int> f;
    int mx=0;
    for (int i=0;i+m<=n;i++) {
        string loc ="";
        for (int j=i;j<i+m;j++) {
            loc += s[j];
        }
        f[loc]++;
        mx = max(mx,f[loc]);
    }
    set<string> elems;
    for (auto elem : f) {
        if (elem.s==mx)
            elems.insert(elem.f);
    }
    cout<<mx<<endl;
    for (auto elem : elems) {
        cout<<elem<<" ";
    }
    return 0;
}
