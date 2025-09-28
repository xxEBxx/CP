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


const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
       double x,y;cin >> x >> y;
        double FC = (x*x + y*y - x*y)/sqrt(x*x + y*y);
        double CH = (x*x + y*y - x*y)/(x*x + y*y);
        CH *= y;
        double FH = sqrt(FC*FC - CH*CH);
        double AG = (y*x - x*x)/y;
        double GH = y - (AG + CH);

        double res = (FH*GH)/2 - atan(GH/FH)*FH*FH/2;
        printf("%.5f\n",res);

    }
    return 0;
}
