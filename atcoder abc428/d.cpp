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

ii trans(ll c,ll d) {
    string mn = to_string(c)+to_string(c+1);
    string mx = to_string(c)+to_string(c+d);

    return {atoll(&mn[0]),atoll(&mx[0])};

}
int cnt(string aa,string bb) {
    int a=atoll(&aa[0]),b=atoll(&bb[0]);
    ll sa = sqrt(a),sb =sqrt(b);
    ll res = sb-sa;
    if (sa*sa==a)
        res++;
    return res;
}

int main() {
    fast();
    ll t;
    cin >> t;
    while (t--) {
        ll c,d;
        cin>>c>>d;
        int nn = to_string(d).size();
        int res=0;
        for (int sz=1;sz<=nn;sz++) {
            if (d==0)break;
            string start = to_string(c);
            string end =start;
            for (int i=0;i<sz;i++) {
                if (i==0)start+='1';
                else start+='0';
                end+='9';
            }
            //is this end availabl ?
            int nend = atoll(&start[0]);
            nend += d;
            if (nend < atoll(&end[0])) {
                end = to_string(nend);
                d=0;
            }
            else {
                d -= atoll(&end[0])-atoll(&start[0]);
            }
            res+=cnt(start,end);

        }

    }
    return 0;
}
