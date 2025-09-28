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

int x[maxn],cnt[maxn],arr[maxn];
vvi g(maxn);

void dfs(int i,int p) {
    x[i] = arr[i];
    for (int c : g[i]) {
        if (c==p)continue;
        dfs(c,i);
        x[i] ^= x[c];
        cnt[i] += cnt[c];
    }
    cnt[i] += (x[i]==0)?1:0 ;
}
vi xoring;
void dfs2(int i,int p) {
    if (x[i] == 0) {
        xoring.push_back(cnt[i]);
        return ;
    }
    for (auto c : g[i] ) {
        if (c==p)continue;
        dfs2(c,i);
    }
}
int main() {
    fast();
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>arr[i];

    for (int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    if (x[1]==0) {
        cout<<"Moamen"<<endl;
    }
    else {
        dfs2(1,1);
        int res=0;
        for (auto elem : xoring)
            res ^= elem;
        if (res!=0)
            cout<<"Moamen"<<endl;
        else
            cout<<"Yassin"<<endl;
    }

    return 0;
}
