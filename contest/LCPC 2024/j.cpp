
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

bool comp(ii a,ii b) {
    if (a.f != b.f)return a.f < b.f;
    return a.s < b.s;
}

int main() {
    fast();
        int n,m;
        cin >> n>>m;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(all(arr));

        vector<ii> p(m);
        for (int i=0;i<m;i++) {
            cin>>p[i].f>>p[i].s;
        }
        sort(all(p));
        multiset<int> curr ;
        //we sorted by first
        int i=0,j = 0; //i index of uniques
        int res=0;
        while (i<n ) {
            while ( j<m && arr[i]>=p[j].f) {
                curr.insert(p[j].s);
                j++;
            }

            while (!curr.empty() && arr[i] > *curr.begin()) {
                curr.erase(curr.begin());
            }
            if (!curr.empty()) {
                curr.erase(curr.begin());
                res++;
            }
            i++;
        }

        cout<<res<<endl;

    return 0;
}
