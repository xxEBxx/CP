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
        int res=0;
        for (int i = 0; i < n; i++) {
            int d1,d2,x,y;
            cin>>d1>>d2>>x>>y;
            if (x==y  && d1*d2==1 || x == m-y && d1*d2==-1)
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
