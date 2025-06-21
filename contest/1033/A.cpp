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

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {
        int l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;

        if (
        b1==b2 && b2==b3 && b1==l1+l2+l3 ||
        l1==l2 && l2==l3 && l1==b1+b2+b3 ||

        l1 == l2 && b3 == b1+b2 && l1+l3 == b3 ||
        l2 == l1 && b3 == b1+b2 && l2+l3 == b3 ||
        l3 == l1 && b2 == b3+b1 && l3+l2 == b2 ||

        l2 == l3 && b1 == b2+b3 && l2+l1 == b1 ||
        l2 == l3 && b1 == b2+b3 && l2+l1 == b1 ||
        l1 == l3 && b2 == b1+b3 && l1+l2 == b2 ||

        b1 == b2 && l3 == l1+l2 && b1+b3 == l3 ||
        b2 == b1 && l3 == l1+l2 && b2+b3 == l3 ||
        b3 == b1 && l2 == l3+l1 && b3+b2 == l2 ||
        b2 == b3 && l1 == l2+l3 && b2+b1 == l1 ||
        b2 == b3 && l1 == l2+l3 && b2+b1 == l1 ||
        b1 == b3 && l2 == l1+l3 && b1+b2 == l2
        )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
