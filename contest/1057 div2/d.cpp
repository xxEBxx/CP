
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;

ll vis[maxn],dp[maxn],cnt;
ll n;
vi arr;
ll solve(ll i) {
    if (i==n)return 0;
    if (i==n-1)return 1e15;
    //we either take 2 or 3
    if (vis[i] == cnt)
        return dp[i];
    ll res = solve(i+2) + abs(arr[i]-arr[i+1]);
    if (i<n-2) {
        ll mx = max(max(arr[i],arr[i+1]),arr[i+2]);
        ll mn = min(min(arr[i],arr[i+1]),arr[i+2]);
        res = min(res,solve(i+3)+mx-mn);
    }
    vis[i]=cnt;
    return dp[i]=res;
}

int main() {
    fast();
    ll t;
    cin >> t;
    memset(vis,-1,sizeof(vis));
    cnt=0;
    while (t--) {
        cin >> n;
        vi arr1(n),arr2(n),arr3(n);

        for (ll i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        cnt++;
        arr=arr1;
        ll res = solve(0);

        for (ll i =0;i<n-1;i++) {
            arr2[i] = arr1[i+1];
        }
        arr2[n-1]=arr1[0];
        cnt++;
        arr=arr2;
        res=min(res,solve(0));

        for (ll i =0;i<n-1;i++) {
            arr3[i] = arr2[i+1];
        }
        arr3[n-1]=arr2[0];
        cnt++;
        arr=arr3;
        res=min(res,solve(0));
        cout<<res<<endl;
    }
    return 0;
}
