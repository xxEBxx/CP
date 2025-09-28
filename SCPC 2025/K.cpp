
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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x=axis in interval [= pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point<double> P;


double segDist(P& s, P& e, P& p) {
    if (s==e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
    oc = a.cross(b, c), od = a.cross(b, d);
    // Checks i f intersection i s single non=endpoint point .
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {all(s)};
}
template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

struct node {
    P a,b;
    int state;//-2 means noth , -1 means start , i means index
    int i;//index in the big seg array
};

double dist(node a,node b) {
    auto rs =  segInter(a.a,a.b,b.a,b.b);
    if(!rs.empty())
        return 0.0;

    double res = segDist(a.a,a.b,b.a);
    res = min(res,segDist(a.a,a.b,b.b));
    res = min(res,segDist(b.a,b.b,a.a));
    res = min(res,segDist(b.a,b.b,a.b));
    return res;
}

struct comp {
    bool operator()(const pair<double,node>& a,const pair<double,node>& b) {
        return a.first > b.first;
    }
};

int main() {
    fast();
    int sx,sy;
    cin>>sx>>sy;

    int n;
    cin>>n;

    int real_n=n;
    vector<node> seg(n+1);
    seg[0] = {P(sx,sy),P(sx,sy),-1,0};
    for (int i=1;i<=n;i++) {

        cin>>seg[i].a.x>>seg[i].a.y>>seg[i].b.x>>seg[i].b.y;
        seg[i].state = -2;
        seg[i].i = i;
    }

    int q;
    cin>>q;
    for (int i=0;i<q;i++) {
        int a,b;
        cin>>a>>b;
        node add = {P(a,b),P(a,b),i,i+n+1};
        seg.push_back(add);
    }

    n=seg.size();
    vector<vector<double>> mat(n,vector<double>(n));
    for (int i=0;i<n;i++) {
        mat[i][i]=0;
        for (int j=i+1;j<n;j++) {
            mat[i][j] = dist(seg[i],seg[j]);
            mat[j][i] = mat[i][j];
        }
    }
    priority_queue<pair<double,node>,vector<pair<double,node>>,comp> pq;//distance between this one and the start
    vector<double> ans(n,1e18);//ths is the new n
    pq.push({0.0,seg[0]});
    ans[0]=0;
    while (!pq.empty()) {
        auto head = pq.top();
        pq.pop();
        if (ans[head.s.i] < head.f)continue;

        for (int j=0;j<n;j++) {
            if (mat[head.s.i][j] + head.f < ans[j] ) {
                ans[j] = mat[head.s.i][j] + head.f;
                pq.push({ans[j], seg[j]});
            }
        }
    }

    for (int i=real_n+1;i<n;i++)
        printf("%.7f\n",ans[i]);

    return 0;
}
