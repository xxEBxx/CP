#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<double, double> ii;
typedef pair<ll, ll> pl;
typedef vector<double> vi;
typedef vector<vector<double> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;


const int maxn = (double) 1e7 + 7;
const double mod = (double) 1e9 + 7;

vi prime(maxn,1);
vector<long double> all_p;
void pre() {
    prime[0]=prime[1]=0;
    for (int i=2;i<maxn;i++) {
        if (prime[i]==0)continue;
        all_p.push_back((long double)i);
        for (int j=i+i;j<maxn;j+=i) {
            prime[j]=0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    pre();
    long double ans = 1.0;
    for (auto elem : all_p) {
        long double prod = (elem*elem)/(elem*elem - 1);
        ans = ans*prod;
    }
    ans++;
    while (t--) {
        long double a,b;
        cin >> a >> b;
        long double aa  = pow(a,ans);
        long double bb = pow(b,ans);
        double res = (bb - aa)/ans;
        printf("%.10f\n",res);
    }

    return 0;
}
