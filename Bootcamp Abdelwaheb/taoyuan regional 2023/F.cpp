
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
struct node {
    int f,s,i;
};
bool comp(node a, node b) {
    if (a.s*b.f == b.s*a.f)return a.i < b.i;
    return a.s*b.f > b.s*a.f;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<node> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].f >> arr[i].s;
            arr[i].i=i;
        }
        sort(all(arr),comp);
        for (int i=0;i<n;i++) {
            cout<<arr[i].i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
