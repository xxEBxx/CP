
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
        string ss;
        vi mxr(n),mnl(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            ss += '0';
        }

        mnl[0] = arr[0];
        for (int i=1;i<n;i++) {
            mnl[i] = min(arr[i],mnl[i-1]);
        }

        mxr[n-1] = arr[n-1];
        for (int i=n-2;i>=0;i--) {
            mxr[i] = max(arr[i],mxr[i+1]);
        }
        ss[0]='1';
        ss[n-1]='1';
        for (int i=1;i<n-1;i++) {
            if (arr[i] == mxr[i] || arr[i] == mnl[i] )
                ss[i]='1';
        }

        cout<<ss<<endl;
    }
    return 0;
}
