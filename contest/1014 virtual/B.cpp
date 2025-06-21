

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
        int n;
        cin >> n;
        vvi arr(n);
        string a,b;
        cin>>a>>b;
        for (int i=0;i<n;i++) {
            arr[i].push_back(a[i]-'0');
            arr[i].push_back(b[i]-'0');
        }
        int h1=0,h2=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<2;j++) {
                if (arr[i][j]==0) {
                    if ((i+j)%2==0)h1++;
                    else h2++;
                }
            }
        }

        if (h2 >= n/2 && h1 >= n-n/2) {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;

    }
    return 0;
}
