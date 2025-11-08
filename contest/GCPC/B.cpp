
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
    int n,t;
    cin >> n>>t;
    vector<ii> arr(n);
    map<int,int> m;
    m[0]=0;
    m[t]=0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].f >> arr[i].s;
        m[arr[i].f]++;
        m[arr[i].s]--;
    }
    int curr=0,last=-1,best=0;
    for (auto elem : m) {
        curr += elem.s;
        if (curr == 0) {
            if (last==-1)
                last = elem.f;
            else {
                best = max(best,elem.f-last);
            }
        }
        else {
            if (last!=-1) {
                best = max(best,elem.f-last);
            }
            last=-1;
        }
    }
    cout<<best<<endl;

    return 0;
}
