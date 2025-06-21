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
        int n;cin >> n;
        vi a(n),b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if (a[n-1]==b[n-1]) {
            cout<<n<<endl;
            continue;
        }
        else if (a[n-2]==b[n-2] ||a[n-2]==a[n-1] || b[n-2]==b[n-1]) {
            cout<<n-1<<endl;
            continue;
        }
        map<int,int> counter;

        counter[a[n-1]]++;
        counter[b[n-1]]++;
        counter[a[n-2]]++;
        counter[b[n-2]]++;
        int res=0;
        for (int i=n-3;i>=0;i--) {
            if (a[i]==b[i]
                || a[i]==b[i+1] && counter[a[i]]>1
                || b[i]==a[i+1] && counter[b[i]]>1
                || b[i]!=a[i+1] && counter[b[i]]>0
                || a[i]!=b[i+1] && counter[a[i]]>0) {
                res = i+1;
                break;
            }
            counter[a[i]]++;
            counter[b[i]]++;
        }
        cout<<res<<endl;

    }
    return 0;
}
