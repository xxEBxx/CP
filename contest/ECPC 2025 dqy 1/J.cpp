
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
    cin>>n;
    int index=0;
    vi arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        if (arr[i]==n)
            index=i;
    }

    int res = 1e9;
    if (index>0 && index<n-1) {
        res = arr[0]+arr[n-1];
    }
    int mx=arr[0];
    for (int i=1;i<index;i++) {
        res = min(res,mx+arr[i]);
        mx=max(mx,arr[i]);
    }
    mx=arr[n-1];
    for (int i=n-2;i>index;i--) {
        res = min(res,mx + arr[i]);
        mx=max(mx,arr[i]);
    }
    cout<<n+res<<endl;
    return 0;
}
