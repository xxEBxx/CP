
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
int n;
vector<int> parent, rank_,black,reach;
void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        reach[a] += reach[b];
        //all blacks on b are passed to a
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main() {
    fast();
    int q;

    cin>>n>>q;
    reach.assign(n+1,0);
    black.assign(n+1,0);
    parent.assign(n+1,0);
    rank_.assign(n+1,0);
    for (int i=1;i<=n;i++)
        make_set(i);

    for (int i=0;i<q;i++) {
        int a;cin>>a;
        if (a==1) {
            int u,v;cin>>u>>v;
            union_sets(u,v);
        }
        else if  (a==2) {
            int v;cin>>v;
            black[v]=1-black[v];
            int p = find_set(v);
            if (black[v])reach[p]++;
            else reach[p]--;
        }
        else {
            int v;
            cin>>v;
            v = find_set(v);
            if (reach[v])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
