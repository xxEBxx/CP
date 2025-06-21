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
        int min_elem=1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            min_elem=min(min_elem,arr[i]);
        }
        string res="Yes";
        for (int i=0;i<n-2;i++) {
            if (arr[i]-arr[i+1] != arr[i+1]-arr[i+2] ) {
                res="No";
                break;
            }
        }
        int diff = abs(arr[1]-arr[0]);
        if ( diff > min_elem)
            res="No";
        else if ( (min_elem-diff) % (n+1) !=0)
            res="No";
        cout<<res<<endl;
    }
    return 0;
}

