
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
        int mx=-1,mn=-1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i]==n)
                mx=i;
            if (arr[i]==1)
                mn=i;
        }
        int res=0;
        if (mn==0)res=arr[1];
        if (mn==n-1)res==arr[n-2];
        if (mn < mx) {
            for (int i=0;i<mn;i++) {
                res=max(res,arr[i]);
            }
        }
        else {
            for (int i=mn+1;i<n;i++) {
                res=max(res,arr[i]);
            }
        }
        cout<<res+n+1<<endl;

    return 0;
}
