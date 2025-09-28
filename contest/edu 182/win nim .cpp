
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

ii ask(int i,int val) {
    cout<<i<<" "<<val<<endl;
    int a,b;
    cin>>a>>b;
    return {a,b};
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        int s=0;
        unordered_map<int,set<int>> bit;
        //elements that have this bit used for msb of S
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s^=arr[i];
        }
        if (s==0) {
            auto res = ask(0,0);
            s ^= arr[res.f];
            for (int j=0;j<32;j++) {
                if (arr[res.f]>>j & 1) {
                    bit[j].erase(res.f);
                }
            }
            arr[res.f] -= res.s;
            for (int j=0;j<32;j++) {
                if (arr[res.f]>>j & 1) {
                    bit[j].insert(res.f);
                }
            }
            s ^= arr[res.f];
        }
        //now s is different than 0

        while (true){
            int msb = 63 - __builtin_ctzll((ll) s);
            int index = *bit[msb].begin();
            ii asked = {index, arr[index] - (arr[index] ^ s)};
            auto res = ask(asked.f, asked.s);
            if (res.f==0 && res.s==0)
                break;
            s ^= arr[res.f];
            for (int j=0;j<32;j++) {
                if (arr[res.f]>>j & 1) {
                    bit[j].erase(res.f);
                }
            }
            arr[res.f] -= res.s;
            for (int j=0;j<32;j++) {
                if (arr[res.f]>>j & 1) {
                    bit[j].insert(res.f);
                }
            }
            s ^= arr[res.f];
        }
    }
    return 0;
}
