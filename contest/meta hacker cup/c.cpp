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
    freopen("test.txt","r",stdin);
    freopen("ans.txt","w",stdout);
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
    int cnt=1;
    while (t--) {
        cout<<"Case #"<<cnt<<": ";
        cnt++;
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i>0)arr[i]^=arr[i-1];
        }
        unordered_map<int,int> c;
        c[0]++;
        for (int i=0;i<n;i++) {
            c[arr[i]]++;
        }
        vi cnt(n+1);
        for (int i=1;i<=n;i++) {
            cnt[i] = cnt[i-1] + i*(i+1)/2;
        }
        int res = cnt[n];


        for(auto elem : c) {
            res -= cnt[elem.s-1];
        }
        cout<<res<<endl;
    }
    return 0;
}
