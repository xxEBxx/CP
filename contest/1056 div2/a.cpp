
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
    int curr=1,before=1;
    cout<<curr<<" "<<curr<<" ";
    for (int i=0;i<100;i++) {
        curr += before;
        before = curr-before;
        if (curr%4==0)
            cout<<curr<<endl;
    }
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;



    }
    return 0;
}
