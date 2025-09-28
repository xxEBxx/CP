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
    int n,m;
    cin>>n>>m;

    vector<string> arr(n);
    vi res(n,0);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for (int j=0;j<m;j++) {
        int cnt=0;
        for (int i=0;i<n;i++) {
            if (arr[i][j]=='0')
                cnt++;
        }

        if (cnt==0 || cnt==n) {
            for (int i=0;i<n;i++) {
                res[i]++;
            }
        }
        else if (cnt < n-cnt) {
            for (int i=0;i<n;i++)
                if (arr[i][j]=='0')res[i]++;

        }
        else {
            for (int i=0;i<n;i++) {
                if (arr[i][j]!='0')
                    res[i]++;
            }
        }
    }

    int mx =0;
    for (int j=0;j<n;j++) {
        mx=max(mx,res[j]);
    }

    for (int j=0;j<n;j++) {
        if (res[j] == mx)
            cout<<j+1<<" ";
    }
    return 0;
}