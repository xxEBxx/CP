#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;


#define int long long


typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
const int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const double EPS = 1e-7;
const int mod = 1e9+7; // 1e9+7, 998244353
// BEFORE coding are you sure you understood the statement correctly?
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.


void burn(int tc) {
    // Here we write the solution
    int n, m; cin >> n >> m;
    vector<int> maxi(m), mini(m);
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        maxi[i] = x;
        mini[i] = x;
    }
    sort(mini.begin(), mini.end());
    sort(maxi.begin(), maxi.end(), [](int a, int b){return a > b;});
    if(n == 1) {
        for(int j = 0; j < 6; j++){
            cout << maxi[0] << " ";
        }
        cout << endl;
        return;
    }
    int i = 0;
    for(; 2*i < n - (n&1); i++) {
        for(int j = 0; j < 6; j++) {
            cout << ((j % 2 == 0) ? mini[i] : maxi[i]) << " ";
        }
        cout << endl;
        for(int j = 0; j < 6; j++) {
            cout << ((j % 2 == 1) ? mini[i] : maxi[i]) << " ";
        }
        cout << endl;
    }
    if(n % 2 == 1){
        for(int j = 0; j < 6; j++) {
            cout << ((j % 2 == 0) ? mini[i] : maxi[i]) << " ";
        }
        cout << endl;
    }
}

signed main()
{
    FAST


    int T = 1;  cin >> T;

    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << i << ": ";
        burn(i);
    }
    return 0;
}