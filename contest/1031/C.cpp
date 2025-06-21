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
        int n,m,k;
        cin >> n>>m>>k;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        int res=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                //if (arr[i][j] != '.')continue;
                int loc=0;
                for (int l=-k;l<=k;l++) {
                    if (j+k >=0 && j+k<m &&
                        i+l >=0 && i+l<n &&
                        arr[i+l][j+k] == 'g')
                        loc++;
                    if (j-k >=0 && j-k<m &&
                        i+l >=0 && i+l<n &&
                        arr[i+l][j-k] == 'g')
                        loc++;
                    if (i+k >=0 && i+k<n &&
                        j+l >=0 && j+l<m &&
                        arr[i+k][j+l] == 'g')
                        loc++;
                    if (i-k >=0 && i-k<n &&
                        j+l >=0 && j+l<m &&
                        arr[i-k][j+l] == 'g')
                        loc++;
                }
                if (i+k<n && j+k<m && arr[i+k][j+k]=='g')loc--;
                if (i+k<n && j-k>=0 && arr[i+k][j-k]=='g')loc--;

                if (i-k>=0 && j+k<m && arr[i-k][j+k]=='g')loc--;
                if (i-k>=0 && j-k>=0 && arr[i-k][j-k]=='g')loc--;

                res=max(res,loc);
            }
        }
        cout<<res<<endl;


    }
    return 0;
}
