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
    int n,m;cin >>n  >>m;
    vector<vector<pair<int,ll>>> g(n+1);
    for (int i=0;i<m;i++) {
        int a,b,c;cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

    vector<ll> distances(n+1,10000000000);
    distances[1] = 0;
    pq.push({0,1});
    while (!pq.empty()) {
        auto h = pq.top();
        pq.pop();
        if (h.first > distances[h.second]) {
            continue;
        }
        for (auto x:g[h.second]) {
            if (h.first + x.second < distances[x.first]) {
                distances[x.first] = h.first + x.second;
                pq.push({distances[x.first],x.first});

            }
        }
    }
    if (distances[n] >= 1000000000) {
        cout << -1 <<endl;
    }
    else {
        cout << distances[n] << endl;
    }




    return 0;
}
