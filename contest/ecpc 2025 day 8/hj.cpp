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
    map<int,vector<string>> ma;
    vector<string> out;
    for (int i=0;i<10;i++) {
        ma[1].push_back(to_string(i));
        ma[2].push_back(to_string(i)+to_string(i));

    }
    for (int i=3;i<=10;i++) {
        string s;
        for (int j=0;j<10;j++) {
            for (string ss : ma[i-2]) {
                s = to_string(j);
                s += ss;
                s += to_string(j);
                ma[i].push_back(s);
            }

        }
    }
    for (int i=1;i<=11;i++) {
        for (string ss : ma[i]){
                if (ss[0] != '0')
                    out.push_back(ss);
                }
    }
    int l = out.size();
    vector<ll> pref(l);
    pref[0] = 0;
    for (int i=1;i<l;i++) {
        ll num = (stoll(out[i]));
        pref[i] = (pref[i-1] + (num-1));
    }
    /*for (int i=0;i<100;i++)
        cout << pref[i] << "  ";*/
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll numm = (n*(n-1))/2;
        int index = lower_bound(pref.begin(),pref.end(),numm)-pref.begin();
        cout << index+1 << endl;
    }


    return 0;
}
