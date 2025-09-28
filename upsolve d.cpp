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
        vi a(n+1,0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vi b=a;
        sort(all(b));
        vi c;
        for (int i=1;i<=n;i++) {
            if (a[i] <= b[k])
                c.push_back(a[i]);
        }

        n = c.size();
        int rest = n;

        int i=0,j=n-1;
        string res = "YES";
        while (i<j) {
            if (c[i]==c[j]) {
                i++;
                j--;
            }
            else if (c[i] == b[k]){
                rest--;
                i++;
            }
            else if (c[j] == b[k]){
                rest--;
                j--;
            }
            else {
                res="NO";
                break;
            }
        }
        if (rest < k-1)res="NO";
        cout<<res<<endl;
    }
    return 0;
}
