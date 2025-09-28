
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

int mex(set<int> arr) {
    int start=0;
    for (auto elem :arr) {
        if (start != elem)break;
        start++;
    }
    return start;
}

int main() {
    fast();
    int n;cin>>n;
    vi grundy(9,0);
    for (int i=2;i<9;i++) {//0 and 1 are loosing
        set<int> loc;
        if (i>=2)
            loc.insert(grundy[i-2]);
        if (i>=3)
            loc.insert(grundy[i-3]);
        if (i>=5)
            loc.insert(grundy[i-5]);
        if (i>=7)
            loc.insert(grundy[i-7]);

        grundy[i] = mex(loc);
    }

    vi arr(n);
    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        int res=0;
        while (a != 0) {
            if (a < b)swap(a,b);
            int occ = a/b;
            a -= b*occ;
            res+=occ;
        }
        res--;
        arr[i] = res%9 ;
    }

    int res = 0;
    for (int i=0;i<n;i++) {
        res ^= grundy[arr[i]];
    }
    if (res == 0)
        cout<<"Second"<<endl;
    else
        cout<<"First"<<endl;

    return 0;
}
