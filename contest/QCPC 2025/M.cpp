
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
        int n;
        cin >> n;
        vi arr(n);
        unordered_map<int,ii> rep;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i&1)rep[arr[i]].f++;
            else rep[arr[i]].s++;
        }
        sort(all(arr));
        bool val=true;

        for (int i=0;i<n;i++) {
            //if even we need an even with him
            if (i&1) {
                rep[arr[i]].f--;
                if (rep[arr[i]].f<0) {
                    val=false;
                    break;
                }
            }
            else {
                rep[arr[i]].s--;
                if (rep[arr[i]].s<0) {
                    val=false;
                    break;
                }
            }
        }
        if (val)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
