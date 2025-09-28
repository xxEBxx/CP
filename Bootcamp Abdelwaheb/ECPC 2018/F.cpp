
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
    ifstream cin("mosalah.in");
    int t;
    cin >> t;
    while (t--) {
        int av,scored,played,rest;
        cin>>av>>scored>>played>>rest;

        int goals_need = av * (played+rest);
        if (scored >= goals_need) {
            cout<<0<<endl;
        }
        else if (rest==0) {
            cout<<-1<<endl;
        }
        else {
            cout<<goals_need - scored<<endl;
        }

    }
    return 0;
}
