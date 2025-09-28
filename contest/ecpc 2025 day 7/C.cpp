
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
    int n,m;cin>>n>>m;
    vector<string> arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int r=0,c=0;
    for (int i=0;i<n;i++) {
        bool valid=true;
        for (int j=0;j<m;j++) {
            if (arr[i][j] != '#') {
                valid=false;
                break;
            }
        }
        if (valid)r++;
    }

    for (int j=0;j<m;j++) {
        bool valid=true;
        for (int i=0;i<n;i++) {
            if (arr[i][j]=='.') {
                valid = false;
                break;
            }
        }
        if (valid)c++;
    }


    cout<<r*c<<" "<<min(n,min(m,max(r,c)))<<endl;
    return 0;
}
