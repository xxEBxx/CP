
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


vector<int> parent, rank_;


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
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}


int main() {
    fast();
    int t;
    cin >> t;
    while (t--) {

        int n,d;

        cin >> n>>d;

        parent.assign(n+1,0);
        rank_.assign(n+1,0);
        vi arr(n+1,0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<ii> arr1(1+n,{0,0});
        for (int i=1;i<=n;i++) {
            arr1[i] = {arr[i],i};
        }
        sort(all(arr1));

        for (int i=1;i<=n;i++) {
            make_set(i);
        }
        for (int i=2;i<=n;i++) {
            if (abs(arr1[i].f-arr1[i-1].f) <= d) {
                union_sets(arr1[i].s,arr1[i-1].s);
            }
        }
        int q;cin>>q;

        for (int i=0;i<q;i++) {
            int a,b;
            cin>>a>>b;
            if (find_set(a) == find_set(b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}
