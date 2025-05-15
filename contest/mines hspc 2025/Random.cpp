#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const vector<int>& arr) {
    vi p(sz(arr));
    rep(i,1,sz(arr)) {
        int g = p[i-1];
        while (g && arr[i] != arr[g]) g = p[g-1];
        p[i] = g + (arr[i] == arr[g]);
    }
    return p;
}

vi match(const vector<int>& s, const vector<int>& pat) {
    vi p;
    for(int elem : pat)
        p.push_back(elem);
    p.push_back(-1);
    for(int elem : s)
        p.push_back(elem);
    p = pi(p);
    vi res;
    rep(i,sz(p)-sz(s),sz(p))
        if (p[i] == sz(pat))
            res.push_back(i - 2 * sz(pat)); // starting index of pat in s
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vi arr(n);
    rep(i,0,n) cin >> arr[i];
    vi pat(m);
    rep(i,0,m) cin >> pat[i];
    vi pat2(k);
    rep(i,0,k) cin >> pat2[i];

    vi occ = match(arr, pat);  // starting indices of b
    vi occ2 = match(arr, pat2); // starting indices of c

    vi st(n,0),end(n,0);
    for(auto elem : occ){
        st[elem + m - 1] = 1;
    }
    for(auto elem : occ2){
        end[elem] = 1;
    }
    ll count=0,start=0;
    for(int i=0;i<n;i++){
        if(st[i] == 1) start++;
        if(end[i] == 1)count += start;

    }
    cout << count;
    return 0;
}
