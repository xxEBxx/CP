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

int solve(vi arr) {
    int n=arr.size();
    int curr_max = arr[0],curr_index=0;
    int res=1;
    for (int i=1;i<n;i++ ) {
        if (arr[i] >= curr_max) {
            curr_index = i;
            curr_max = arr[i];
        }
        res = max(res,i-curr_index+1);
    }
    return res;
}

int main() {
    fast();
    int n;cin>>n;
    vi arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vi arr2 = arr;
    reverse(all(arr));

    cout<<max(solve(arr),solve(arr2))<<endl;

    return 0;
}
