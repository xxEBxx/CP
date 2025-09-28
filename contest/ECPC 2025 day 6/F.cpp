
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
        vi arr(n,0);
        for (int i = 0; i < n; i++) {
            string s;cin>>s;
            for (int j=0;j<m;j++) {
                if (s[j]=='1') {
                    arr[i] = m-j;
                    break;
                }
            }
        }

        //grundy of 0 is 0 , grundy of 1 is 1
        //grundy of k+1 is 0 again then 1 then 2..
        int res=0;
        for (int i=0;i<n;i++) {
            res ^= arr[i]%(k+1);
        }

        if (res==0)
            cout<<"Hala"<<endl;
        else
            cout<<"Faris"<<endl;

    }
    return 0;
}
