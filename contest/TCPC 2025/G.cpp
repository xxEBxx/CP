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
        int n,m;
        cin >> n>>m;
        vector<multiset<int>> arr(m);
        for (int i = 0; i < n; i++) {
            for (int j=0;j<m;j++) {
                int val;
                cin>>val;
                arr[j].insert(val);
            }
        }
        int res=0;

        for (int i=0;i<n;i++) {
            int j = 0,curr=0;
            while (j < m) {
                if (curr > *arr[j].rbegin())break;
                auto it = arr[j].lower_bound(curr);
                curr = *it;
                arr[j].erase(it);
                j++;
            }
            if (j==m)
                res++;
            else
                break;
        }
        cout<<res<<endl;

    }
    return 0;
}
