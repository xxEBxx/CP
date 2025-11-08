#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn = (ll) 2 * 1e5 + 7;
const ll mod = (ll) 1e9 + 7;
#define sz(x) (ll)(x).size()

template <class T> ll sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Poll {
    typedef Poll P;
    T x, y;
    explicit Poll(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return abs(x) + abs(y); }
    //double dist() const { return sqrt((double)dist2()); }
    // angle to x=axis in llerval [= pi , pi ]
    double angle() const { return atan2(y, x); }
    //P unit() const { return *this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    //P normal() const { return perp().unit(); }
    // returns poll rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef long long T;
typedef Poll<T> P;
const T INF = numeric_limits<T>::max();
bool on_x(const P& a, const P& b) { return a.x < b.x; }
bool on_y(const P& a, const P& b) { return a.y < b.y; }
struct Node {
    P pt; // i f t h i s i s a leaf , the single poll in i t
    T x0 = INF, x1 = -INF, y0 = INF, y1 = -INF; // bounds
    Node *first = 0, *second = 0;
    T distance(const P& p) { // min squared distance to a poll
        T x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);
        T y = (p.y < y0 ? y0 : p.y > y1 ? y1 : p.y);
        return (P(x,y) - p).dist2();
    }
    T maxDistance(const P& p) const {
        T dx = std::max(std::abs(p.x - x0), std::abs(p.x - x1));
        T dy = std::max(std::abs(p.y - y0), std::abs(p.y - y1));
        return {P(dx,dy).dist2()};
    }
    Node(vector<P>&& vp) : pt(vp[0]) {
        for (P p : vp) {
            x0 = min(x0, p.x); x1 = max(x1, p.x);
            y0 = min(y0, p.y); y1 = max(y1, p.y);
        }
        if (vp.size() > 1) {
            // s p l i t on x i f width >= height (not ideal . . . )
            sort(all(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);
            // divide by taking h a l f the array for each child (not
            // best performance with many duplicates in the middle)
            ll half = sz(vp)/2;
            first = new Node({vp.begin(), vp.begin() + half});
            second = new Node({vp.begin() + half, vp.end()});
        }
    }
};
struct KDTree {
    Node* root;
    KDTree(const vector<P>& vp) : root(new Node({all(vp)})) {}
    //if u want closest point
    pair<T, P> search(Node *node, const P& p) {
        if (!node->first) {
            // uncomment i f we should not find the poll i t s e l f :
            // i f (p == node=>pt ) return {INF, P()};
            return make_pair((p - node->pt).dist2(), node->pt);
        }
        Node *f = node->first, *s = node->second;
        T bfirst = f->distance(p), bsec = s->distance(p);
        if (bfirst > bsec) swap(bsec, bfirst), swap(f, s);
        // search c l o s e s t side f i r s t , other side i f needed
        auto best = search(f, p);
        if (bsec < best.first)
            best = min(best, search(s, p));
        return best;
    }
    //if u want farthest point
    pair<T,P> farthest(Node* node, const P& q) {
        if (!node->first)                       // leaf
            return { (q - node->pt).dist2(), node->pt };

        Node *a = node->first, *b = node->second;
        T farA = a->maxDistance(q), farB = b->maxDistance(q);

        /* visit the child whose box *could* be farther first */
        if (farB > farA) { std::swap(farA, farB); std::swap(a, b); }

        auto best = farthest(a, q);             // best so far (max distance)

        if (farB > best.first)                  // prune if b cannot beat best
            best = std::max(best, farthest(b, q));

        return best;
    }
    pair<T, P> nearest(const P& p) {
        return search(root, p);//change for furthest
    }
};

int main() {
    ll n,m,f,b;
    cin>>n>>m>>f>>b;
    vector<P> arr(b);
    for (ll i =0;i<b;i++) {
        cin>>arr[i].x>>arr[i].y;
    }
    KDTree kd(arr);
    ll q;
    cin>>q;
    for (ll i=0;i<q;i++) {
        P a;
        cin>>a.x>>a.y;
        ll d = kd.farthest(kd.root,a).f;

        if (d < f) {
            cout<<"YES"<<endl;
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
