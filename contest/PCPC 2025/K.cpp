
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
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
    int n,k;
    cin >> n >> k;
    string s;
    cin>>s;
    vector<string> arr(k);
    for (int i=0;i<k;i++)
        cin >> arr[i];

    vector<vector<int>> occ(k);
    for (int i =0;i<k;i++) {
        for (int j=0;j<n-arr[i].length()+1;j++) {
            bool tr = true;
            for (int k1=j;k1<j+arr[i].length();k1++) {
                if (s[k1] != arr[i][k1-j]) {
                    tr = false;
                    break;
                }
            }
            if (tr)
                occ[i].push_back(j);
        }
    }
    vector<int> order(k,0);

    for (int i=0;i<k;i++)
        order[i] = i;

    bool tr = false;
    do {
        if (occ[order[0]].empty())
            break;

        int endd = occ[order[0]][0] + arr[order[0]].length();
        bool find = true;
        for (int i=1;i<k;i++) {
            if (occ[order[i]].empty()) {
                find = false;
                break;
            }
            if (endd > *occ[order[i]].rbegin()) {
                find = false;
                break;
            }
            int start  = lower_bound(occ[order[i]].begin(),occ[order[i]].end(),endd) - occ[order[i]].begin();

            endd =  occ[order[i]][start] + arr[order[i]].length();
        }
        if (find) {
            tr = true;
            break;
        }
    } while (next_permutation(order.begin(),order.end()));
    if (tr)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
