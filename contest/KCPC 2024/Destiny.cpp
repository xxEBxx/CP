
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

const int maxn = (int) 3 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

struct obj {
    int l,r;
};
int b = sqrt(maxn);
bool comp(obj x, obj y) {
    if (x.l / b == y.l / b)
        return x.r < y.r;
    return x.l / b < y.l / b;
}


int main() {
    fast();
    int n,m;
    vi arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    for (int i=0;i<m;i++) {
        
    }
    return 0;
}
