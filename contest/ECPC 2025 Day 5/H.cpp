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
        string s;
        cin>>s;
        vi res(n);
        res[0]=0;
        int skipped = -1,curr=1;

        for (int i=2;i<=n;i++) {
            if (s[i]=='0') {
                if (skipped == -1) {
                    skipped = curr;
                    curr++;
                }
                res[i-1]=curr;
                curr++;
            }
            else {
                if (skipped != -1) {
                    res[i-1] = skipped;
                    skipped = -1;
                }
                else{
                    res[i-1] = curr;
                    curr++;
                }

            }
        }
        for (auto elem : res)
            cout<<elem<<" ";
        cout<<endl;
    }
    return 0;
}
