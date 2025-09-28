
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<double, double> ii;
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

const int maxn = (int) 100 +1;
const int mod = (int) 1e9 + 7;

int n;
double k;
ii arr[maxn];

double distance(ii a,ii b) {
    return sqrt((a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s));
}
ii vect_dir(ii a, ii b) {
    ii res = {b.f-a.f,b.s-a.s};
    double norm = sqrt(res.f*res.f+res.s*res.s);
    res.f /=norm;
    res.s /=norm;
    return res;
}
bool work(double r) {
    ii curr_c = arr[0];
    double curr_r = r;

    for (int i=1;i<n;i++) {
        double dist  = distance(curr_c,arr[i]);
        curr_r =  min(dist+r,curr_r) - max(-curr_r,dist-r);
        curr_r /=2;

        double dist_next_center = (min(dist+r,curr_r) + max(-curr_r,dist-r))/2;
        ii vect_d = vect_dir(curr_c,arr[i]);
        curr_c.f += dist_next_center * vect_d.f;
        curr_c.s += dist_next_center * vect_d.s;
    }

    return curr_r >= k;
}


int main() {
    fast();
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].f >> arr[i].s;
    }

    double mn = 0 , mx=1e7;

    while (mx-mn > (double)1e5) {
        double mid = (mx+mn)/2;
        if (work(mid))
            mx =mid;
        else
            mn =mid;
    }
    cout<<mn<<endl;
    return 0;
}
