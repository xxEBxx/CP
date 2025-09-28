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
    int n,x;
    cin>>n>>x;
    unordered_map<int,int> curr,last;
    for (int i=0;i<n;i++) {
        int val;
        cin>>val;
        if (val%x != 0)continue;
        //m[val]=max(1,m[val]*2);
        for (auto elem : last) {
            if (gcd(elem.f,val)%x==0){
                curr[gcd(elem.f, val)] += elem.s;
                curr[gcd(elem.f, val)] %= mod;
            }
        }
        curr[val]++;
        last = curr;
    }
    cout<<curr[x]<<endl;
    return 0;
}
