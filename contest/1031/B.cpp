
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
    int n,m;cin>>n>>m;
    map<string,deque<int>> count;
    for (int i=0;i<n;i++) {
        string a,mini;int b;
        cin>>a>>b;
        for (int i=0;i<5;i++) {
            mini += a[i];
        }
        count[mini].back(b);
    }

    int res=0;
    for (int i=0;i<m;i++) {
        string a,b;
        cin>>a>>b;
        //if (count[b].empty())continue;
        if (a=="Low"){
            res += *count[b].begin();
            count[b].erase(count[b].begin());
        }
        else {
            res += *count[b].rbegin();
            count[b].erase(prev(count[b].end()));
        }
    }
    cout<<res<<endl;

    return 0;
}