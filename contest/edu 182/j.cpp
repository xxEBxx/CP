
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

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn )
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        // query [ b , e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n+1),b(n+1);
        Tree sta(n+1),stb(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sta.update(i,a[i]);
        }

        for (int i = 1; i <= n; i++){
            cin >> b[i];
            stb.update(i,b[i]);
        }

        int q;
        cin>>q;
        while (q--) {
            int l,r;
            cin>>l>>r;
            int min_a=n,min_b=n;
            if (l>1) {
                min_a = min(min_a,sta.query(1,l));
                min_b = min(min_b,stb.query(1,l));
            }
            if (r<n) {
                min_a = min(min_a,sta.query(r+1,n+1));
                min_b = min(min_b,stb.query(r+1,n+1));
            }
            cout<<abs(min_a-min_b)<<endl;
        }

    }
    return 0;
}
