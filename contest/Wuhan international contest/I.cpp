

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
        if (k < n || k > (n*n-n+1) ) {
            cout<<"No"<<endl;
            continue;
        }
        vvi arr(n,vi(n,-1));
        for (int i=0;i<n-1;i++) {
            arr[0][i] = i+1;
        }

        set<int> all;
        for (int i=n;i<=n*n;i++) {
            all.insert(i);
        }

        arr[0][n-1]=k;
        all.erase(k);
        for (int i=1;i<n;i++) {
            int high = *all.rbegin();
            all.erase(high);
            arr[i][i-1]=high;
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (arr[i][j] == -1) {
                    int high = *all.rbegin();
                    all.erase(high);
                    arr[i][j]=high;
                }
            }
        }
        cout<<"Yes"<<endl;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
