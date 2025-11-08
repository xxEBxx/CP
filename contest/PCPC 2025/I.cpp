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
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    set<int> comp;
    for (int i =0 ; i<=n ; i++)
        comp.insert(i);

    int i=0,j=0;
    //we akways try to insert j
    int res =0;
    int res_mex = 0;
    while (j<n) {

        if (comp.find(arr[j]) != comp.end()) {
            comp.erase(arr[j]);
            j++;
        }
        else {
            comp.insert(arr[i]);
            i++;
        }

        if (*comp.begin() > res_mex) {
            res = j - i ;
            res_mex = *comp.begin();
        }
        else if (*comp.begin() == res_mex) {
            res = max(res,j - i );
        }
    }
    if (*comp.begin() > res_mex) {
        res = j - i ;
    }
    else if (*comp.begin() == res_mex) {
        res = max(res,j - i );
    }

    cout<<res<<endl;
    return 0;
}
