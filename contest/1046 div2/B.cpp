
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
        int n,k;
        cin>>n>>k;
        string s;cin>>s;
        bool ex=true;
        for (int i=0;i<n;i++) {
            int j=i;
            while (j<n && s[j]=='1') {
                j++;
            }
            if (j-i >= k) {
                ex=false;
                break;
            }
            i=j;
        }
        if (!ex) {
            cout<<"NO"<<endl;
            continue;
        }
        int curr=1;
        vi res(n);
        for (int i=0;i<n;i++) {
            if (s[i]=='1'){
                res[i] = curr;
                curr++;
            }
        }
        for (int i=0;i<n;i++) {
            if (s[i]!='1'){
                res[i] = curr;
                curr++;
            }
        }
        cout<<"YES"<<endl;
        for (auto elem : res)
            cout<<elem<<" ";
        cout<<endl;
    }
    return 0;
}
