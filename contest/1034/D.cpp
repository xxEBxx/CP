

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
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;
        string s;cin>>s;
        int c1=0;
        int st = n-k-1,en = k;
        for (int i=0;i<n;i++) {
            if (i<=st || i>=en ) {
                if (s[i]=='1')c1++;
            }
        }
        if (c1 <= k && k >= n/2)cout<<"ALICE"<<endl;
        else cout<<"BOB"<<endl;
    }
    return 0;
}
