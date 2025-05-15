#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int n;
    cin >> n;
    map<string,int> index;
    vector<pair<int,int>> pos(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int a,b;cin >> a >> b;
        index[s] = i;
        pos[i] = {a,b};
    }
    long long res = 0;
    string s1,s2;cin >> s1;
    for(int i=1;i<n;i++){
        cin >> s2;
        int j,k;
        j = index[s2];k = index[s1];
        res += (abs(pos[j].f - pos[k].f) + abs(pos[j].s - pos[k].s));
        s1 = s2;
        s2 = "";
    }
    cout << res ;
    return 0;
}