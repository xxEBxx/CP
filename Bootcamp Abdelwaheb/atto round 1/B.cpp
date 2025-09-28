
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
        int n,m;
        cin >> n>>m;
        string s;
        cin>>s;
        m--;
        if (m==0 || m==n-1) {
            cout<<1<<endl;
            continue;
        }

        if (s[m+1]=='#' ||s[m-1]=='#') {
            cout<<min(m+1,n-m)<<endl;
            continue;
        }

        int r=-1,l=-1;
        for (int i=0;i<m;i++) {
            if (s[i]=='#')l=i;
        }
        for (int i=n-1;i>m;i--) {
            if (s[i]=='#')r=i;
        }
        if(l==-1 && r==-1) {
            cout<<1<<endl;
            continue;
        }
        int dist_l=l+1,dist_r;
        if (r==-1)dist_r=0;
        else dist_r = n-1-r;


        cout<<min(min(m+1,n-m),max(dist_l,dist_r)+1)<<endl;
    }
    return 0;
}
