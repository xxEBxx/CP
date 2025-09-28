
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
        int n,j,k;
        cin >> n>>j>>k;
        vi arr(n+1,0);
        int max_val=0;
        for (int i = 1; i < 1+n; i++) {
            cin >> arr[i];
            max_val=max(max_val,arr[i]);
        }
        if (k >= 2 || max_val==arr[j])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
    return 0;
}
