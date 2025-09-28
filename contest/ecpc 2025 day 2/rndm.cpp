
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

int n,c;
vi arr;
bool work(int x) {
    int taken =0;
    for (int i=0;i<n;) {
        taken++;
        if (taken>=c)return true;

        int next = arr[i] + x;
        if (next > arr[n-1])break;
        i = lower_bound(all(arr),next) - arr.begin();
    }
    return taken >=c;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        cin >> n>>c;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(all(arr));
        int mn=1,mx=1e9;
        while (mn+1 < mx) {
            int mid = (mn+mx)/2;
            if (work(mid)) {
                mn = mid;
            }
            else {
                mx = mid-1;
            }
        }
        if (work(mx)) cout<<mx<<endl;
        else cout<<mn<<endl;
    }
    return 0;
}
