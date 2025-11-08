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
        int n,x;
        cin >> n>>x;
        vi arr(n);
        unordered_map<int,multiset<int>> m;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            m[i%x].insert(arr[i]);
        }

        vi arr2;
        for (int i=0;i<n;i++) {
            arr2.push_back(*m[i%x].begin());
            m[i%x].erase(m[i%x].begin());
        }
        bool ex=true;
        for (int i=1;i<n;i++) {
            if (arr2[i]<arr2[i-1])
                ex=false;
        }
        if (ex) {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
