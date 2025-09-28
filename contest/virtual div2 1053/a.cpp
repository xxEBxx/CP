
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
        vi arr(m);
        int mx=0;
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
            mx=max(arr[i],mx);
        }
        bool sorted = true;
        for (int i = 1; i < m; i++) {
            if (arr[i]!=arr[i-1]+1){
                sorted = false;
                break;
            }
        }
        if (sorted) {
            cout<< n +1- mx<<endl;
        }
        else {
            cout<<1<<endl;
        }
    }
    return 0;
}
