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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int costmit = 1e6,costmti = 1e6;
    string pat = "mit";
    string s2 = "";

    for (int i=0;i<n/3;i++)
        s2 += pat;
    s2 += pat.substr(0,n%3);


    int tot = 0;
    for (int i=0;i<n;i++) {
            if (s[i] != s2[i])
                tot++;
    }
    costmit = min(costmit,tot);
    pat = "itm";
    s2 = "";
    for (int i=0;i<n/3;i++)
        s2 += pat;
    s2 += pat.substr(0,n%3);
    tot = 0;
    for (int i=0;i<n;i++) {
        if (s[i] != s2[i])
            tot++;
    }
    costmit = min(costmit,tot);

    pat = "tmi";
    s2 = "";
    for (int i=0;i<n/3;i++)
        s2 += pat;
    s2 += pat.substr(0,n%3);
    tot = 0;
    for (int i=0;i<n;i++) {
        if (s[i] != s2[i])
            tot++;
    }
    costmit = min(costmit,tot);


    pat = "mti";
    s2 = "";

    for (int i=0;i<n/3;i++)
        s2 += pat;
    s2 += pat.substr(0,n%3);


    tot = 0;
    for (int i=0;i<n;i++) {
        if (s[i] != s2[i])
            tot++;
    }
    costmti = min(costmti,tot);
    pat = "tim";
    s2 = "";
    for (int i=0;i<n/3;i++)
        s2 += pat;
    s2 += pat.substr(0,n%3);
    tot = 0;
    for (int i=0;i<n;i++) {
        if (s[i] != s2[i])
            tot++;
    }
    costmti = min(costmti,tot);

    pat = "imt";
    s2 = "";
    for (int i=0;i<n/3;i++)
        s2 += pat;
    s2 += pat.substr(0,n%3);
    tot = 0;
    for (int i=0;i<n;i++) {
        if (s[i] != s2[i])
            tot++;
    }
    costmti = min(costmti,tot);

    if (costmit == costmti)
        cout << "FAKE";
    else {
        if (costmit < costmti)
            cout << "mit " << costmit;
        else
            cout << "mti " << costmti;
    }



    return 0;
}
