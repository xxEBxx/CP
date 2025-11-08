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
        string s;
        cin>>s;
        int n=s.size();
        string odd="",even="";
        for (int i =0;i<n;i++) {
            if (s[i]-'0' & 1)
                odd.push_back(s[i]);
            else
                even.push_back(s[i]);
        }
        int i=0,j=0;
        n=odd.size();
        int m=even.size();
        string res="";
        while (i<n && j<m) {
            if (odd[i] < even[j]) {
                res.push_back(odd[i]);
                i++;
            }
            else {
                res.push_back(even[j]);
                j++;
            }
        }
        while (i<n) {
            res.push_back(odd[i]);
            i++;
        }
        while (j<m) {
            res.push_back(even[j]);
            j++;
        }
        cout<<res<<endl;
    }
    return 0;
}
