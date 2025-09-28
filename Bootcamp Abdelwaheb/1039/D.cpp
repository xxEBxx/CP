#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x)     begin(x), end(x)
#define sz(x)      (int)(x).size()

using ll = long long;
using C  = complex<double>;
using vd = vector<double>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R((double)2,(double)1);
    static vector<C> rt;
    for (static int k = 2; k < n; k <<= 1) {          // pre-compute roots
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acosl(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = (i & 1) ? R[i >> 1] * x : R[i >> 1];
    }
    vector<int> rev(n);
    rep(i, 0, n) rev[i] = (rev[i >> 1] | ((i & 1) << L)) >> 1;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int k = 1; k < n; k <<= 1)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k) {
                C z = rt[j + k] * a[i + j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j]     += z;
            }
}

vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    int need = sz(a) + sz(b) - 1;
    int L    = 32 - __builtin_clz(need);
    int n    = 1 << L;

    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);

    fft(in);
    for (auto& x : in) x *= x;

    rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);

    vd res(need);
    rep(i, 0, need) res[i] = imag(out[i]) / (4 * n);
    return res;
}

int main() {
    fast();

    int k, n, m;
    if (!(cin >> k >> n >> m)) return 0;

    vd a(k+1, 0.0), b(k+1, 0.0);

    /* ---- read multiset A ---- */
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
            a[v]++;
    }

    /* ---- read multiset B ---- */
    for (int i = 0; i < m; ++i) {
        int v; cin >> v;
            b[v]++;
    }

    vd res = conv(a, b);               // size = 2*k-1

    int upper = min<int>(sz(res) - 1, 2 * k - 2);
    for (int s = 1; s <= upper; ++s) {
        cout << llround(res[s]) << (s == upper ? '\n' : ' ');
    }
    return 0;
}
