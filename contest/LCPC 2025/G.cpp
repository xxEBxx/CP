
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
        if (n==0 || n==1 || n==2) {
            cout<<0<<endl<<endl;
            continue;
        }
        n--;
        cout<<n<<endl;
        string res="";
        for (int i=0;i<n;i++) {
            if (i&1)res+='B';
            else res+='F';
        }
        res[res.size()-1] = 'B';
        cout<<res;
        cout<<endl;
    }
    return 0;
}
