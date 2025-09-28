
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

template<class I> vi lis(const vector<I>& S) {
    if (S.empty()) return {};
    vi prev(sz(S));
    typedef pair<I, int> p;
    vector<p> res;
    rep(i,0,sz(S)) {
        // change 0 => i for longest non=decreasing subsequence
        auto it = lower_bound(all(res), p{S[i], 0});
        if (it == res.end()) res.emplace_back(), it = res.end()-1;
        *it = {S[i], i};
        prev[i] = it == res.begin() ? 0 : (it-1)->second;
    }
    int L = sz(res), cur = res.back().second;
    vi ans(L);
    while (L--) ans[L] = cur, cur = prev[cur];
    return ans;
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }


        vi ls = lis(arr);
        map<int,int> ess;
        for (auto elem : ls)
            ess[elem]++;
        cout<<endl;
        vi arr1=arr;
        reverse(all(arr1));
        for (int i=0;i<n;i++)
            arr1[i] =- arr1[i];
        vi ls1 = lis(arr1);
        for (auto elem : ls1)
            ess[n-1-elem]++;

        for (int i=0;i<n;i++) {
            if (ess[i]==2)
                cout<<ls1.size()-1<<" ";
            else
                cout<<ls1.size()<<" ";
        }
        cout<<endl;

    }
    return 0;
}
